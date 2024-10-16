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

### Branch Naming Scheme and Rulesets

We are following a structured branching model to ensure smooth collaboration and maintain code quality across our project.

#### **Branch Structure**:

- **`main`**: The main production-ready branch.
- **`dev`**: All features and hotfixes are integrated here before merging into `main`.
- **`feature/your-feature`**: For developing new features. When working on a feature, follow this workflow:
  - Create a `feature/your-feature` branch from `dev`.
  - You can commit directly to the feature branch without creating sub-branches. If you prefer, you can create sub-branches for specific tasks, such as `feature/your-feature/subtask`.

- **`hotfix/your-hotfix`**: For urgent fixes. You can push directly to a `hotfix/*` branch, or if needed, create sub-branches such as `hotfix/your-hotfix/subtask`.

#### **Workflow**:
1. **Working in a Feature Branch**:
   - **Create a feature branch** from `dev` (e.g., `feature/your-feature`).
   - You can commit directly to the feature branch. If desired, you can create sub-branches (e.g., `feature/your-feature/subtask`).
   - Once the feature is complete, submit a pull request to merge the feature branch into `dev`.

2. **Working with Hotfixes**:
   - For urgent fixes, create a branch directly from `main` or `dev` with the naming convention `hotfix/your-hotfix`.
   - You can push directly to the `hotfix/*` branch, or optionally create sub-branches (e.g., `hotfix/your-hotfix/subtask`), and then create a pull request to merge into `dev` and `main`.

#### **Branch Rulesets**:

1. **`main`**:
   - No direct pushes allowed; all changes must go through pull requests.
   - Requires at least 4 approvals before merging.
   - Requires linear history (no merge commits).
   - Commits must be signed and verified.

2. **`dev`**:
   - No direct pushes allowed; changes must go through pull requests.
   - Requires at least 2 approvals before merging.
   - Requires linear history (no merge commits).

3. **`feature/*`**:
   - You can commit directly to the feature branch, or if preferred, create sub-branches for specific tasks.
   - Once the feature is complete, a pull request is required to merge the feature branch into `dev`.

4. **`hotfix/*`**:
   - You can push directly to a `hotfix/*` branch, or if preferred, create sub-branches for specific tasks.
   - You must create a pull request to merge into `dev` and `main`.

This system ensures code is integrated smoothly while maintaining flexibility for individual developers during feature development.

### Other Available Commands

- `make class CLASS=ClassName`: Create a new class with header and source files.
- `make ctest TEST=TestName`: Create a new test file in the `tests` directory.
- `make docs`: Generate Doxygen documentation.
- `make leaks`: Check for memory leaks.

### Project Diagrams

We have prepared several diagrams to help visualize the architecture and flow of the project. You can access all the diagrams on our Lucid Charts team board:

🔗 **[Lucid charts](https://lucid.app/lucidchart/6e509cca-4ff4-4916-80f2-b78223818bf3/edit?view_items=c6DgXFr46dar&invitationId=inv_b33ae7ae-4790-4b55-aff6-ef27bfa26008)**

Please use your tuks email for signup as there is pro version.
