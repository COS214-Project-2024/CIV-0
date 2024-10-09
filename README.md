# Civ Zero

Welcome to **Civ Zero**! This project is a C++ application that includes unit testing and coverage reports. Below are the instructions to get started with this project.

## Getting Started

### Prerequisites

Ensure you have the following installed on your system:
- A C++ compiler (`g++` or `clang++`)
- `make` utility

### Step 1: Setup

Before you can compile and run the project, you need to set up the project structure. This includes creating the necessary directories and downloading any required dependencies.

To set up the project, run:

```bash
make setup
```

This command will:
- Create the source, build, binary, docs, and tests directories.
- Generate a basic `main.cpp` file in the `src` directory.
- Download `doctest.h` (for unit testing) into the `tests` directory.
- Create a sample test file in the `tests` directory.

### Step 2: Compiling and Running the Project

Once the setup is complete, you can compile and run the project.

To compile and run the project, use the following command:

```bash
make run
```

### Step 3: Running Unit Tests

To run the unit tests, use the following command:

```bash
make test
```

### Step 4: Generating Coverage Report (Optional)

To generate a code coverage report, use the following command:

```bash
make coverage
```

The coverage report will be generated in the `coverage` directory as an HTML file.

### Cleaning the Build

To clean the build artifacts, you can run:

```bash
make clean
```

This will remove all compiled files and the coverage reports.

### Other Available Commands

- `make class CLASS=ClassName`: Create a new class with header and source files.
- `make ctest TEST=TestName`: Create a new test file in the `tests` directory.
- `make docs`: Generate Doxygen documentation.
- `make leaks`: Check for memory leaks.

### Project Diagrams

We have prepared several diagrams to help visualize the architecture and flow of the project. You can access all the diagrams on our Miro team board:

🔗 **[Miro Team Boards](https://miro.com/welcome/S2hpakhKMVc2QXJNTDU3QmZUNVMySDBieVJYM3FUdFRTOXF6Q2xFdFdjVEtJRTdVNXE3N05iR0h0U0xHbDViWHwzNDU4NzY0NTg4MzM2MTM4NDcyfDE=?share_link_id=556175432229)**

Please ensure you have access to the Miro team or request access if necessary.
