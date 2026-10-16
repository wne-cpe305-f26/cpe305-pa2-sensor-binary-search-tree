# CPE305 Programming Assignment 02

Complete an owning binary search tree that stores the latest reading for each sensor ID.

The complete assignment specification is distributed through Kodiak and links to this starter repository.

## Required work

Implement the `SensorTree` operations in `src/sensor_tree.cpp` and add at least six focused tests to `tests/student_tests.cpp`.

Do not change the public interface, member names, or deleted copy operations in `include/sensor_tree.hpp`.

## Build and test

Run commands from the repository root:

```sh
make
./bin/sensor_tree
make test
make sanitize
make clean
```

The supplied `Makefile` requires a C++20 `g++` or `clang++` compiler. To use Clang explicitly, run `make CXX=clang++`.

## Design notes

Replace this section with 150–250 words that:

- state the ordering and ownership invariants;
- explain why inorder traversal produces increasing sensor IDs; and
- compare the shapes produced by insertion orders `1,2,3,4,5` and `3,1,5,2,4`, including why tree height can be `O(n)`.

## Optional Codespaces environment

GitHub Codespaces is optional. Select **Code**, then **Codespaces**, then **Create codespace on main**. The container builds the tests after creation. Running `make test` will fail until the required functions are implemented.

You may instead clone or download the repository and work locally on macOS or Linux.

## Submission archive

Create the ZIP only after your implementation and tests pass:

```sh
make clean
zip -r submission.zip . -x 'submission.zip' '.git/*' 'bin/*' 'build/*' '.vscode/*'
```

Open the ZIP and confirm that it contains the complete source tree before uploading it through Kodiak.
