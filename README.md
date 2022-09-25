# Simple Shell project - iShell -

This is a simple UNIX command interpreter based on bash and Sh.

## Overview

**iShell** is an sh-compatible command line interpreter that executes commands read from the standard input or from a file.

### Invocation:

**Compilation:**
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o iShell
```

**Usage:**
iShell can be invoked interactively and non-interactively.

#### Interactive invocation

When iShell is invoked with the standard input connected to the terminal (as determined by isatty(3)), the interactive mode is activated and the following prompt will be displayed ``myShell:)``

Example:
```
$./iShell
myShell:)
```
#### Non-interactive invocation

When iShell is invoked with the standard input disconnected from the terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'Hello World!'" | ./iShell
'Hello World!'
$
```

When **iShell** is invoked with a command line argument, **iShell** takes the first argument as a file to read commands for execution.

Example:

```
$ echo "echo 'Command from a file'" > text
$ ./iShell text
'Command from a file'
$
```
