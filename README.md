# Minishell

This README provides detailed information about the "Minishell" project, including its objectives, instructions, and requirements.

## Summary
This project is about creating a simple shell, essentially your own little bash. You will learn a lot about processes and file descriptors.

## Version
7.1

## Contents
1. [Introduction](#introduction)
2. [Common Instructions](#common-instructions)
3. [Mandatory Part](#mandatory-part)
4. [Bonus Part](#bonus-part)

## Introduction
The existence of shells is linked to the very existence of IT. Initially, developers found communicating with a computer using aligned 1/0 switches extremely irritating. It was only logical that they created software to communicate with computers using interactive command lines in a language somewhat close to human language.

With Minishell, you’ll be able to travel through time and experience the problems faced when graphical user interfaces didn't exist.

## Common Instructions
- Your project must be written in C.
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check, and you will receive a 0 if there is a norm error inside.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.) apart from undefined behaviors. If this happens, your project will be considered non-functional and will receive a 0 during the evaluation.
- All heap-allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- If the subject requires it, you must submit a Makefile that will compile your source files to the required output with the flags `-Wall`, `-Wextra`, and `-Werror`, use `cc`, and your Makefile must not relink.
- Your Makefile must at least contain the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.
- To turn in bonuses to your project, you must include a rule `bonus` in your Makefile, which will add all the various headers, libraries, or functions that are forbidden in the main part of the project. Bonuses must be in a different file `_bonus.{c/h}` if the subject does not specify otherwise. Mandatory and bonus part evaluations are done separately.
- If your project allows you to use your `libft`, you must copy its sources and its associated Makefile into a `libft` folder with its associated Makefile. Your project’s Makefile must compile the library using its Makefile, then compile the project.
- We encourage you to create test programs for your project even though they won’t have to be submitted or graded. They will help you test your work and your peers’ work easily. These tests are especially useful during your defense. During the defense, you can use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error occurs in any section of your work during Deepthought’s grading, the evaluation will stop.

## Mandatory Part
### Program Name
`minishell`

### Turn-in Files
`Makefile`, `*.h`, `*.c`

### Makefile
`NAME`, `all`, `clean`, `fclean`, `re`

### Arguments
None

### External Functions
- `readline`
- `rl_clear_history`
- `rl_on_new_line`
- `rl_replace_line`
- `rl_redisplay`
- `add_history`
- `printf`
- `malloc`
- `free`
- `write`
- `access`
- `open`
- `read`
- `close`
- `fork`
- `wait`
- `waitpid`
- `wait3`
- `wait4`
- `signal`
- `sigaction`
- `sigemptyset`
- `sigaddset`
- `kill`
- `exit`
- `getcwd`
- `chdir`
- `stat`
- `lstat`
- `fstat`
- `unlink`
- `execve`
- `dup`
- `dup2`
- `pipe`
- `opendir`
- `readdir`
- `closedir`
- `strerror`
- `perror`
- `isatty`
- `ttyname`
- `ttyslot`
- `ioctl`
- `getenv`
- `tcsetattr`
- `tcgetattr`
- `tgetent`
- `tgetflag`
- `tgetnum`
- `tgetstr`
- `tgoto`
- `tputs`

### Libft Authorized
Yes

### Description
Write a shell that should:
- Display a prompt when waiting for a new command.
- Have a working history.
- Search and launch the right executable based on the `PATH` variable or using a relative or absolute path.
- Avoid using more than one global variable to indicate a received signal. This global variable cannot provide any other information or data access than the number of a received signal.
- Not interpret unclosed quotes or special characters which are not required by the subject, such as `\` (backslash) or `;` (semicolon).
- Handle `'` (single quote) to prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle `"` (double quote) to prevent the shell from interpreting the metacharacters in the quoted sequence except for `$` (dollar sign).
- Implement redirections:
  - `<` should redirect input.
  - `>` should redirect output.
  - `<<` should be given a delimiter, then read the input until a line containing the delimiter is seen. It doesn’t have to update the history.
  - `>>` should redirect output in append mode.
- Implement pipes (`|` character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- Handle environment variables (`$` followed by a sequence of characters) which should expand to their values.
- Handle `$?` which should expand to the exit status of the most recently executed foreground pipeline.
- Handle `ctrl-C`, `ctrl-D`, and `ctrl-\` which should behave like in bash.
- In interactive mode:
  - `ctrl-C` displays a new prompt on a new line.
  - `ctrl-D` exits the shell.
  - `ctrl-\` does nothing.
- Implement the following builtins:
  - `echo` with option `-n`
  - `cd` with only a relative or absolute path
  - `pwd` with no options
  - `export` with no options
  - `unset` with no options
  - `env` with no options or arguments
  - `exit` with no options

The `readline()` function can cause memory leaks. You don’t have to fix them. However, your own code should not have memory leaks. Limit yourself to the subject description. Anything not required is not needed. If in doubt, refer to bash as a reference.

## Bonus Part
Your program has to implement:
- `&&` and `||` with parenthesis for priorities.
- Wildcards `*` should work for the current working directory.

The bonus part will only be assessed if the mandatory part is perfect. Perfect means the mandatory part has been entirely completed and works without malfunctioning. If you have not passed all the mandatory requirements, your bonus part will not be evaluated.
