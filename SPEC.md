# Mini Regression Framework — Specification

Version: 0.1.0
Author: Bibek Chandra Dey
Date: 2026-05-19

---

## 1. What is a Test?

A test is a standalone executable file that:
- Lives somewhere inside the tests/ directory tree
- Is discovered automatically by the framework at runtime
- Is executed as a child process by the framework
- Reports pass or fail via its exit code

A test is NOT:
- A shell script (not supported in v0.1.0)
- A function inside the framework itself
- A file with a specific naming convention (any executable counts)

---

## 2. What Does Pass and Fail Mean?

Pass:  exit code 0
Fail:  any non-zero exit code

The framework does not inspect stdout or stderr to determine
pass/fail. Exit code is the only signal.

---

## 3. Minimum Test Metadata

Every discovered test must have:
- name      — derived from the filename, no extension
- path      — absolute path to the executable
- timeout   — maximum seconds allowed to run (default: 30)

---

## 4. Test Result

After execution every test produces:
- status    — PASS, FAIL, or TIMEOUT
- duration  — wall clock time in milliseconds
- stdout    — captured standard output
- stderr    — captured standard error
- exit_code — raw exit code from the process

---

## 5. Test Discovery Rules

- Walk the directory tree given as argument recursively
- A file is a test if it is executable (has execute permission)
- Subdirectories are walked in alphabetical order
- Tests within a directory are sorted alphabetically
- Symlinks are followed
- Hidden files (starting with .) are ignored

---

## 6. Execution Rules

- Each test runs as a completely isolated child process
- Tests do not share memory, file handles, or environment state
- Each test gets its own temporary working directory
- Environment variables are inherited from parent unless overridden
- A test exceeding its timeout is killed immediately (SIGKILL)

---

## 7. Exit Code of the Framework

- 0  — all tests passed
- 1  — one or more tests failed or timed out

---

## 8. What is Out of Scope for v0.1.0

- Shell script tests
- Test dependencies (one test depending on another)
- Test skipping
- Test retries (added in Phase 5)
- Parallel execution (added in Phase 3)
- Filtering (added in Phase 2)
- Config file (added in Phase 2)
