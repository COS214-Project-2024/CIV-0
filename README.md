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
  - Create sub-branches for specific tasks (e.g., `feature/your-feature/subtask`).
  - Work on the subtask branch, and once complete, create a pull request to merge the subtask into the main `feature/your-feature` branch.
  - **Only one review is required** to merge the subtask into the main feature branch, and you can approve it yourself.
  
  - Once all subtasks are complete, create a pull request to merge the `feature/your-feature` branch into `dev`, which requires the usual review process.

- **`hotfix/your-hotfix`**: For urgent fixes. You can push directly to a `hotfix/*` branch and create a pull request to merge it into `dev` and `main`.

#### **Workflow**:
1. **Working in a Feature Branch**:
   - **Create a feature branch** from `dev` (e.g., `feature/your-feature`).
   - For each task under that feature, create a sub-branch (e.g., `feature/your-feature/subtask`).
   - Work on the subtask, and when it's ready, submit a pull request to merge it back into `feature/your-feature`. This requires one review, which can be done by yourself.
   - Once all subtasks are merged into the feature branch, submit a pull request to merge the feature branch into `dev`.

2. **Working with Hotfixes**:
   - For urgent fixes, create a branch directly from `main` or `dev` with the naming convention `hotfix/your-hotfix`.
   - You can push directly to the `hotfix/*` branch and then create a pull request to merge into `dev` and `main`.

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
   - **Create sub-branches** from a feature branch for specific tasks.
   - You must submit a pull request to merge a subtask back into the main feature branch. Only one review is required, and you can review it yourself.
   - Once all subtasks are complete, a pull request is required to merge the feature branch into `dev`.

4. **`hotfix/*`**:
   - You can push directly to a `hotfix/*` branch.
   - You must create a pull request to merge into `dev` and `main`.

This system ensures code is integrated smoothly while maintaining flexibility for individual developers during feature development.

### Other Available Commands

- `make class CLASS=ClassName`: Create a new class with header and source files.
- `make ctest TEST=TestName`: Create a new test file in the `tests` directory.
- `make docs`: Generate Doxygen documentation.
- `make leaks`: Check for memory leaks.

### Project Diagrams

We have prepared several diagrams to help visualize the architecture and flow of the project. You can access all the diagrams on our Miro team board:

🔗 **[Miro Team Boards](https://miro.com/welcome/S2hpakhKMVc2QXJNTDU3QmZUNVMySDBieVJYM3FUdFRTOXF6Q2xFdFdjVEtJRTdVNXE3N05iR0h0U0xHbDViWHwzNDU4NzY0NTg4MzM2MTM4NDcyfDE=?share_link_id=556175432229)**

Please ensure you have access to the Miro team or request access if necessary.
