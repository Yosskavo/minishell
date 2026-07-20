# 42 Minishell 101

Welcome to **Minishell 101**! This is a beginner-friendly guide and README template for the 42 School `minishell` project. The goal of this project is to create a simple UNIX shell—a program that takes commands from the user and executes them, much like `bash`.

---

## Overview

Minishell is a journey into process creation, file descriptors, signals, and parsing. By the end of this project, you'll have a deep understanding of how your terminal interprets what you type and how it asks the operating system to do the work.

### Core Features

*   **Prompt:** Displays a prompt when waiting for a new command.
*   **History:** Keeps a working history of commands (using `readline`).
*   **Execution:** Finds and executes executables using the `PATH` variable or relative/absolute paths.
*   **Built-ins:** Recreates 7 essential built-in functions (see below).
*   **Pipes (`|`):** Connects the output of one command to the input of the next.
*   **Redirections:**
    *   `>` (Redirect output)
    *   `<` (Redirect input)
    *   `>>` (Redirect output in append mode)
    *   `<<` (Here-document)
*   **Environment Variables:** Expands variables like `$USER` or `$?` (exit status).
*   **Signals:** Handles `ctrl-C`, `ctrl-D`, and `ctrl-\` just like bash.

---

## The 7 Built-in Commands

Your shell must natively implement the following commands without calling external binaries:

1.  `echo` (with `-n` option)
2.  `cd` (with relative or absolute paths)
3.  `pwd` (print working directory)
4.  `export` (export environment variables)
5.  `unset` (unset environment variables)
6.  `env` (print the environment)
7.  `exit` (exit the shell, handling exit codes)

---

## Architecture 101 (How it works)

A well-structured minishell usually follows these four steps:

1.  **Lexer (Tokenization):** Breaks the user's input string into small, manageable chunks (tokens) like `WORD`, `PIPE`, `REDIRECT_IN`, etc.
2.  **Parser:** Organizes those tokens into a structure (like an Abstract Syntax Tree or a linked list of commands) that the computer can easily understand.
3.  **Expander:** Loops through the parsed arguments and replaces any `$VARIABLES` with their actual values from the environment.
4.  **Executor:** Iterates through the command structures. It sets up pipes and redirections (using `dup2`), forks processes (using `fork`), and runs the commands (using `execve` or built-in functions).

---

## Installation & Usage

### Compilation

To compile the project, simply run `make` in the root directory.

```bash
make
```

### Running the Shell

Start the shell by running the executable:

```bash
./minishell
```

### Cleaning Up

*   `make clean`: Removes the object files.
*   `make fclean`: Removes object files and the executable.
*   `make re`: Recompiles the whole project.

---

## Resources & Tips

*   **Waitpid & Fork:** Understand how parent processes wait for child processes.
*   **File Descriptors:** Grasp how `dup2()` is used to wire `stdout` of one process into the `stdin` of another.
*   **Memory Leaks:** `valgrind` is your best friend. Make sure you free your abstract syntax tree or command lists after every prompt loop!
*   **Bash is your standard:** Whenever you are unsure how minishell should behave, type the same command into `bash` and mimic its behavior.

---
*Created for the 42 Cursus (yel-mota).*
