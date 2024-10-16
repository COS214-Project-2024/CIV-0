# Variables
PROJECT_NAME = project
SRCDIR = src
TESTDIR = tests
BUILDDIR = build
COVERAGE_BUILDDIR = $(BUILDDIR)/coverage
BINDIR = bin
DOCSDIR = docs
COVERAGEDIR = coverage
TARGET = $(BINDIR)/$(PROJECT_NAME)
TEST_TARGET = $(BINDIR)/$(PROJECT_NAME)_tests
ZIP_FILE_NAME = $(PROJECT_NAME).zip
TEMP_DIR = temp
DOXYFILE = Doxyfile
DOCTEST_URL = https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h

# OS detection
OS := $(shell uname)

# Compiler
ifeq ($(OS), Darwin)
    CXX = clang++
else
    CXX = g++
endif

# Coverage flags
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage

# Include directories (add all the folders with header files)
INCLUDES = -I$(SRCDIR) -I$(TESTDIR)

# Compiler flags
CXXFLAGS += -std=c++17

# Main source and object (normal build)
MAIN_SRC = $(SRCDIR)/main.cpp
MAIN_OBJ = $(BUILDDIR)/src/main.o

# Find all .cpp files in src excluding main.cpp (only if src directory exists)
SOURCES := $(if $(wildcard $(SRCDIR)/*),$(filter-out $(MAIN_SRC), $(shell find $(SRCDIR) -name '*.cpp')))
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/src/%.o, $(SOURCES))

# Coverage build objects
COVERAGE_OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(COVERAGE_BUILDDIR)/src/%.o, $(SOURCES))

# Test files and objects
TEST_SOURCES := $(if $(wildcard $(TESTDIR)/*),$(shell find $(TESTDIR) -name '*.cpp'))
TEST_OBJECTS := $(patsubst $(TESTDIR)/%.cpp, $(BUILDDIR)/tests/%.o, $(TEST_SOURCES))
COVERAGE_TEST_OBJECTS := $(patsubst $(TESTDIR)/%.cpp, $(COVERAGE_BUILDDIR)/tests/%.o, $(TEST_SOURCES))

# Compile and link the program (normal build)
$(TARGET): $(OBJECTS) $(MAIN_OBJ)
	@mkdir -p $(BINDIR)
	@$(CXX) $(OBJECTS) $(MAIN_OBJ) $(CXXFLAGS) -o $(TARGET)

# Compile and link the test executable (normal build, exclude main.cpp)
$(TEST_TARGET): $(OBJECTS) $(TEST_OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJECTS) $(TEST_OBJECTS) $(CXXFLAGS) -o $(TEST_TARGET)

# Compile and link the program (coverage build)
$(BINDIR)/$(PROJECT_NAME)_coverage: $(COVERAGE_OBJECTS)
	@mkdir -p $(BINDIR)
	@$(CXX) $(COVERAGE_OBJECTS) $(CXXFLAGS) $(COVERAGE_FLAGS) -o $(BINDIR)/$(PROJECT_NAME)_coverage

# Compile and link the test executable (coverage build, exclude main.cpp)
$(BINDIR)/$(PROJECT_NAME)_tests_coverage: $(COVERAGE_OBJECTS) $(COVERAGE_TEST_OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(COVERAGE_OBJECTS) $(COVERAGE_TEST_OBJECTS) $(CXXFLAGS) $(COVERAGE_FLAGS) -o $(BINDIR)/$(PROJECT_NAME)_tests_coverage

# Compile each .cpp file into an object file (normal build)
$(BUILDDIR)/src/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

# Compile each .cpp file into an object file (coverage build)
$(COVERAGE_BUILDDIR)/src/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -c $< -o $@ $(INCLUDES)

# Compile test files into object files (normal build)
$(BUILDDIR)/tests/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDES)

# Compile test files into object files (coverage build)
$(COVERAGE_BUILDDIR)/tests/%.o: $(TESTDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -c $< -o $@ $(INCLUDES)

# Clean build and coverage files
clean:
	@if [ -d $(BUILDDIR) ] && [ "$$(ls -A $(BUILDDIR))" ]; then \
        rm -rf $(BUILDDIR)/*; \
        echo "\033[1;32m✓ Cleaned build directory: $(BUILDDIR)\033[0m"; \
	fi
	@if [ -d $(BINDIR) ] && [ "$$(ls -A $(BINDIR))" ]; then \
        rm -rf $(BINDIR)/*; \
        echo "\033[1;32m✓ Cleaned binary directory: $(BINDIR)\033[0m"; \
	fi
	@if [ -d $(COVERAGEDIR) ] && [ "$$(ls -A $(COVERAGEDIR))" ]; then \
        rm -rf $(COVERAGEDIR)/*; \
        echo "\033[1;32m✓ Cleaned coverage directory: $(COVERAGEDIR)\033[0m"; \
	fi

# Run the compiled project (normal build, without coverage flags)
run: $(TARGET)
	@$(TARGET)

# Run tests
test: $(TEST_TARGET)
	@$(TEST_TARGET)

# Memory leak detection (macOS uses `leaks`, Linux uses `valgrind`)
leaks: test
	@if [ "$(OS)" = "Darwin" ]; then \
	    export MallocStackLogging=1; \
	    leaks -atExit --list -- $(TEST_TARGET) | awk 'BEGIN { print "Memory Leak Summary:\\n" } /^Process/ { print } /^Leak/ { print }'; \
	elif [ "$(OS)" = "Linux" ]; then \
	    valgrind --leak-check=full --track-origins=yes $(TEST_TARGET); \
	else \
	    echo "Unsupported OS for memory leak check. Please use macOS or Linux."; \
	fi

# Run tests and generate coverage report
coverage: $(BINDIR)/$(PROJECT_NAME)_tests_coverage
	@mkdir -p $(COVERAGEDIR)
	@$(BINDIR)/$(PROJECT_NAME)_tests_coverage
	@gcovr -r . --exclude='$(TESTDIR)/.*' --html --html-details -o $(COVERAGEDIR)/index.html
	@gcovr -r . --exclude='$(TESTDIR)/.*' --print-summary
	@echo "Coverage report generated in the 'coverage' directory."

# Setup initial project structure with necessary folders
setup:
	@if [ ! -d $(SRCDIR) ]; then \
	    mkdir -p $(SRCDIR); \
	    echo "\033[1;32m✓ Created source directory: $(SRCDIR)\033[0m"; \
	fi
	@if [ ! -d $(BUILDDIR) ]; then \
	    mkdir -p $(BUILDDIR); \
	    echo "\033[1;32m✓ Created build directory: $(BUILDDIR)\033[0m"; \
	fi
	@if [ ! -d $(BINDIR) ]; then \
	    mkdir -p $(BINDIR); \
	    echo "\033[1;32m✓ Created binary directory: $(BINDIR)\033[0m"; \
	fi
	@if [ ! -d $(DOCSDIR) ]; then \
	    mkdir -p $(DOCSDIR); \
	    echo "\033[1;32m✓ Created docs directory: $(DOCSDIR)\033[0m"; \
	fi
	@if [ ! -d $(TESTDIR) ]; then \
	    mkdir -p $(TESTDIR); \
	    echo "\033[1;32m✓ Created tests directory: $(TESTDIR)\033[0m"; \
	fi
	@if [ ! -f $(SRCDIR)/main.cpp ]; then \
	    echo '#include <iostream>' > $(SRCDIR)/main.cpp; \
	    echo '' >> $(SRCDIR)/main.cpp; \
	    echo 'int main() {' >> $(SRCDIR)/main.cpp; \
	    echo '    std::cout << "Hello, World!" << std::endl;' >> $(SRCDIR)/main.cpp; \
	    echo '    return 0;' >> $(SRCDIR)/main.cpp; \
	    echo '}' >> $(SRCDIR)/main.cpp; \
	    echo "\033[1;32m✓ Created main.cpp in $(SRCDIR)\033[0m"; \
	fi
	@if [ ! -f $(TESTDIR)/doctest.h ]; then \
	    curl -sSL $(DOCTEST_URL) -o $(TESTDIR)/doctest.h; \
	    echo "\033[1;32m✓ Downloaded doctest.h into $(TESTDIR)\033[0m"; \
	fi
	@if [ ! -f $(TESTDIR)/test_main.cpp ]; then \
	    echo '#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN' > $(TESTDIR)/test_main.cpp; \
	    echo '#include "doctest.h"' >> $(TESTDIR)/test_main.cpp; \
	    echo '' >> $(TESTDIR)/test_main.cpp; \
	    echo "\033[1;32m✓ Created test_main.cpp in $(TESTDIR)\033[0m"; \
	fi
	@if [ ! -f $(TESTDIR)/sample_test.cpp ]; then \
	    echo '#include "doctest.h"' > $(TESTDIR)/sample_test.cpp; \
	    echo '' >> $(TESTDIR)/sample_test.cpp; \
	    echo 'TEST_CASE("Sample test") {' >> $(TESTDIR)/sample_test.cpp; \
	    echo '    CHECK(1 == 1);' >> $(TESTDIR)/sample_test.cpp; \
	    echo '}' >> $(TESTDIR)/sample_test.cpp; \
	    echo "\033[1;32m✓ Created sample_test.cpp in $(TESTDIR)\033[0m"; \
	fi
	@echo "\033[1;33mℹ Project setup complete!\033[0m"

# Doxygen Setup and Configuration
doxygen:
	@if [ ! -f $(DOXYFILE) ]; then \
	    doxygen -g $(DOXYFILE); \
	    echo "\033[1;32m✓ Doxygen configuration file created at $(DOXYFILE)\033[0m"; \
	fi
	@if [ "$(OS)" = "Darwin" ]; then \
	    sed -i '' 's|^INPUT .*|INPUT = src|' $(DOXYFILE); \
	    sed -i '' 's|^FILE_PATTERNS .*|FILE_PATTERNS = *.cpp *.h|' $(DOXYFILE); \
	    sed -i '' 's|^OUTPUT_DIRECTORY .*|OUTPUT_DIRECTORY = $(DOCSDIR)/doxygen|' $(DOXYFILE); \
	    sed -i '' 's|^RECURSIVE .*|RECURSIVE = YES|' $(DOXYFILE); \
	else \
	    sed -i 's|^INPUT .*|INPUT = src|' $(DOXYFILE); \
	    sed -i 's|^FILE_PATTERNS .*|FILE_PATTERNS = *.cpp *.h|' $(DOXYFILE); \
	    sed -i 's|^OUTPUT_DIRECTORY .*|OUTPUT_DIRECTORY = $(DOCSDIR)/doxygen|' $(DOXYFILE); \
	    sed -i 's|^RECURSIVE .*|RECURSIVE = YES|' $(DOXYFILE); \
	fi

# Generate Doxygen documentation
docs: doxygen
	@mkdir -p $(DOCSDIR)/doxygen
	doxygen $(DOXYFILE)

# Clean Doxygen documentation
clean-docs:
	@rm -rf $(DOCSDIR)/doxygen/*

# Declare 'class' as a phony target
.PHONY: class

# Create new class with header and source files
class:
	@if [ "$(CLASS)" = "" ]; then \
	    class_path=$(subst src/,,$(word 2,$(MAKECMDGOALS))); \
	else \
	    class_path=$(CLASS); \
	fi; \
	if echo "$$class_path" | grep -q '/'; then \
	    dir_path=$(SRCDIR)/$$(dirname $$class_path); \
	    class_name=$$(basename $$class_path); \
	else \
	    dir_path=$(SRCDIR); \
	    class_name=$$class_path; \
	fi; \
	mkdir -p $$dir_path; \
	header_file=$$dir_path/$$class_name.h; \
	source_file=$$dir_path/$$class_name.cpp; \
	header_guard=$$(echo "$$class_name" | tr '[:lower:]' '[:upper:]')_H; \
	if [ ! -f $$header_file ]; then \
	    echo "\033[1;32m✓ Creating header file: $$header_file\033[0m"; \
	    echo "#ifndef $$header_guard" > $$header_file; \
	    echo "#define $$header_guard" >> $$header_file; \
	    echo "" >> $$header_file; \
	    echo "class $$class_name" >> $$header_file; \
	    echo "{" >> $$header_file; \
	    echo "public:" >> $$header_file; \
	    echo "    $$class_name();" >> $$header_file; \
	    echo "    ~$$class_name();" >> $$header_file; \
	    echo "};" >> $$header_file; \
	    echo "" >> $$header_file; \
	    echo "#endif // $$header_guard" >> $$header_file; \
	else \
	    echo "\033[1;33mℹ Header file already exists: $$header_file\033[0m"; \
	fi; \
	if [ ! -f $$source_file ]; then \
	    echo "\033[1;32m✓ Creating source file: $$source_file\033[0m"; \
	    echo "#include \"$$class_name.h\"" > $$source_file; \
	    echo "" >> $$source_file; \
	    echo "$$class_name::$$class_name() {}" >> $$source_file; \
	    echo "$$class_name::~$$class_name() {}" >> $$source_file; \
	else \
	    echo "\033[1;33mℹ Source file already exists: $$source_file\033[0m"; \
	fi; \
	exit 0;

# Ignore extra arguments
%:
	@:

# Declare 'create-test' as a phony target for creating new test files
.PHONY: create-test

# Create new test file in tests/ directory by default
ctest:
	@if [ "$(TEST)" = "" ]; then \
	    test_path=$(word 2,$(MAKECMDGOALS)); \
	else \
	    test_path=$(TEST); \
	fi; \
	if echo "$$test_path" | grep -q '/'; then \
	    dir_path=$(TESTDIR)/$$(dirname $$test_path); \
	    test_name=$$(basename $$test_path); \
	else \
	    dir_path=$(TESTDIR); \
	    test_name=$$test_path; \
	fi; \
	mkdir -p $$dir_path; \
	test_file=$$dir_path/$$test_name.cpp; \
	if [ ! -f $$test_file ]; then \
	    echo "\033[1;32m✓ Creating test file: $$test_file\033[0m"; \
	    echo '#include "doctest.h"' > $$test_file; \
	    echo '' >> $$test_file; \
	    echo 'TEST_CASE("'$$test_name' test") {' >> $$test_file; \
	    echo '    // Add your test cases here' >> $$test_file; \
	    echo '    CHECK(1 == 1);' >> $$test_file; \
	    echo '}' >> $$test_file; \
	else \
	    echo "\033[1;33mℹ Test file already exists: $$test_file\033[0m"; \
	fi; \
	exit 0;

# Ignore extra arguments
%:
	@:

# Modified zip command to remove context from #include paths
zip:
	@mkdir -p $(TEMP_DIR)/$(PROJECT_NAME)
	@echo "\033[1;32m✓ Created temporary directory: $(TEMP_DIR)/$(PROJECT_NAME)\033[0m"
	# Find all .cpp and .h files and copy them into the temp directory
	@find $(SRCDIR) -type f \( -name '*.cpp' -o -name '*.h' \) -exec cp {} $(TEMP_DIR)/$(PROJECT_NAME) \;
	@echo "\033[1;32m✓ Copied .cpp and .h files to $(TEMP_DIR)/$(PROJECT_NAME)\033[0m"
	# Process each file to modify #include statements by stripping the path
	@find $(TEMP_DIR)/$(PROJECT_NAME) -type f \( -name '*.cpp' -o -name '*.h' \) -exec sed -i '' -E 's|#include "(.*)/([^/]+)"|#include "\2"|' {} \;
	@echo "\033[1;32m✓ Processed #include statements to strip paths\033[0m"
	# Create a simple Makefile inside the zip folder
	@echo "\033[1;32m✓ Creating Makefile inside $(TEMP_DIR)/$(PROJECT_NAME)\033[0m"
	@echo 'CXX = g++' > $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'PROJECT_NAME = $(PROJECT_NAME)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'TARGET = $$(PROJECT_NAME)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'SOURCES = $$(wildcard *.cpp)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'OBJECTS = $$(SOURCES:.cpp=.o)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'all: $$(TARGET)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '%.o: %.cpp' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '	$$(CXX) -std=c++17 -c $$< -o $$@' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '$$(TARGET): $$(OBJECTS)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '	$$(CXX) -std=c++17 -o $$(TARGET) $$(OBJECTS)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'clean:' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '	rm -f $$(OBJECTS) $$(TARGET)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo 'run: all' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile
	@echo '	./$$(TARGET)' >> $(TEMP_DIR)/$(PROJECT_NAME)/Makefile

	@echo "\033[1;32m✓ Created Makefile in the temp directory\033[0m"
	# Zip the project folder with all .cpp and .h files and the Makefile
	@cd $(TEMP_DIR) && zip -r ../$(ZIP_FILE_NAME) $(PROJECT_NAME)/* > /dev/null
	@echo "\033[1;32m✓ Project zipped as $(ZIP_FILE_NAME)\033[0m"
	# Clean up
	@rm -rf $(TEMP_DIR)
	@echo "\033[1;32m✓ Cleaned up temporary directory\033[0m"

# Create or overwrite .gitignore file
gitignore:
	@echo "\033[1;32m✓ Creating or updating .gitignore file\033[0m"
	@echo "# Ignore prerequisites" > .gitignore
	@echo "*.d" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Compiled object files" >> .gitignore
	@echo "*.slo" >> .gitignore
	@echo "*.lo" >> .gitignore
	@echo "*.o" >> .gitignore
	@echo "*.obj" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Precompiled headers" >> .gitignore
	@echo "*.gch" >> .gitignore
	@echo "*.pch" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Compiled dynamic libraries" >> .gitignore
	@echo "*.so" >> .gitignore
	@echo "*.dylib" >> .gitignore
	@echo "*.dll" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Compiled static libraries" >> .gitignore
	@echo "*.lai" >> .gitignore
	@echo "*.la" >> .gitignore
	@echo "*.a" >> .gitignore
	@echo "*.lib" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Executables" >> .gitignore
	@echo "*.exe" >> .gitignore
	@echo "*.out" >> .gitignore
	@echo "*.app" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Build and binary directories" >> .gitignore
	@echo "build/" >> .gitignore
	@echo "bin/" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Coverage files" >> .gitignore
	@echo "*.gcno" >> .gitignore
	@echo "*.gcda" >> .gitignore
	@echo "coverage/" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Other files" >> .gitignore
	@echo "*.log" >> .gitignore
	@echo "*.swp" >> .gitignore
	@echo "*.bak" >> .gitignore
	@echo "*~" >> .gitignore
	@echo "/.vscode" >> .gitignore
	@echo "/submit" >> .gitignore
	@echo "*.zip" >> .gitignore
	@echo ".DS_Store" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Ignore doctest.h in tests folder" >> .gitignore
	@echo "tests/doctest.h" >> .gitignore
	@echo "" >> .gitignore

	@echo "# Ignore Doxygen configuration and output" >> .gitignore
	@echo "Doxyfile" >> .gitignore
	@echo "docs/doxygen/" >> .gitignore
	@echo "\033[1;32m✓ .gitignore file created or updated successfully\033[0m"

hеlp:
	@echo "\033[1;35m🎉 CONGRATULATIONS! You have unlocked the sacred Makefile Easter Egg! 🎉\033[0m"
	@sleep 1
	@echo "\033[1;36mHere's your random dose of motivation (or confusion):\033[0m"
	@quotes=("\"Debugging: Because no one writes perfect code, except me. Just kidding, I’m in deep trouble.\" 😅" \
		"\"Keep calm and semicolon;\" 😎" \
		"\"Why do Java developers wear glasses? Because they don’t C#.\" 🤓" \
		"\"I would love to change the world, but they won’t give me the source code.\" 🌍" \
		"\"In case of emergency, git commit and push. Then panic.\" 😱" \
		"\"To err is human. To blame someone else is even more human.\" 🤡" \
		"\"404 Motivation not found.\" 😵" \
		"\"There are 10 types of people in the world: those who understand binary and those who don’t.\" 🔢" \
		"\"I have a bad feeling about this… Ah yes, it's a merge conflict.\" ⚔️" \
		"\"The only kind of joke a JavaScript developer can understand: callback humor.\" 😂" \
		"\"I was going to optimize my code… but I wrote this Easter egg instead.\" 🐣" \
		"\"I told my computer I needed a break. Now it won’t stop sending me Kit-Kats.\" 🍫" \
		"\"99 little bugs in the code, 99 little bugs. Take one down, patch it around, 127 bugs in the code.\" 🐛" \
		"\"How many programmers does it take to change a light bulb? None, that’s a hardware problem!\" 💡" \
		"\"There’s no place like 127.0.0.1\" 🏠"); \
	rand=$$((RANDOM % $${#quotes[@]})); \
	echo "\033[1;33m$${quotes[$$rand]}\033[0m";
	@echo "\033[1;32mYou've been blessed with this random wisdom. Now go forth and conquer your bugs! 🐛👨‍💻\033[0m"

# Help command
help:
	@echo "\033[1;33mMakefile Help:\033[0m"
	@echo ""
	@echo "\033[1;32mTargets:\033[0m"
	@echo "  \033[1;36msetup\033[0m             - Set up initial project structure with necessary folders and main.cpp."
	@echo "  \033[1;36mclass\033[0m             - Create a new class with header and source files."
	@echo "                        Syntax: make class CLASS=ClassName or make class folder/ClassName."
	@echo "  \033[1;36mctest\033[0m             - Create a new test file in the tests/ directory."
	@echo "                        Syntax: make ctest TEST=TestName or make ctest folder/TestName."
	@echo "  \033[1;36mrun\033[0m               - Compile and run the project (normal build)."
	@echo "  \033[1;36mtest\033[0m              - Compile and run unit tests (normal build)."
	@echo "  \033[1;36mcoverage\033[0m          - Compile the project, run the tests with coverage flags, and generate a coverage report in the 'coverage' folder."
	@echo "  \033[1;36mzip\033[0m               - Zip all files and folders in src and include a simple Makefile."
	@echo "  \033[1;36mclean\033[0m             - Clean build artifacts (object files, executables, coverage files, and build directories)."
	@echo "  \033[1;36mdoxygen\033[0m           - Set up Doxygen configuration file."
	@echo "  \033[1;36mdocs\033[0m              - Generate Doxygen documentation."
	@echo "  \033[1;36mclean-docs\033[0m        - Clean Doxygen documentation."
	@echo "  \033[1;36mleaks\033[0m             - Check for memory leaks using leaks on macOS or valgrind on Linux."

# Phony targets
.PHONY: setup setup-tests class run test zip clean help doxygen docs clean-docs coverage leaks