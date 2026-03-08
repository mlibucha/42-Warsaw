*This project has been created as part of the 42 curriculum by mlibucha.*

## Description
`pipex` is a 42 project focused on UNIX process management and pipes.
The program reproduces this shell behavior:

```bash
< file1 cmd1 | cmd2 > file2
```

Executable format:

```bash
./pipex file1 "cmd1" "cmd2" file2
```

The mandatory implementation handles:
- opening input/output files
- creating a pipe
- forking two child processes
- redirecting stdin/stdout with `dup2`
- resolving command paths from `PATH`
- executing commands with `execve`
- propagating the second command exit status

Bonus implementation additionally handles:
- multiple pipes (`cmd1 | cmd2 | ... | cmdn`)
- `here_doc` mode with append output (`>>`)

## Instructions
### Compilation
```bash
make
```

Available Make targets:
- `make` or `make all`
- `make clean`
- `make fclean`
- `make re`

### Usage
```bash
./pipex infile "ls -l" "wc -l" outfile
```

Equivalent shell command:
```bash
< infile ls -l | wc -l > outfile
```

Another example:
```bash
./pipex infile "grep a1" "wc -w" outfile
```

Equivalent shell command:
```bash
< infile grep a1 | wc -w > outfile
```

### Bonus usage
Multiple pipes:
```bash
./pipex infile "cmd1" "cmd2" "cmd3" outfile
```
Equivalent shell command:
```bash
< infile cmd1 | cmd2 | cmd3 > outfile
```

`here_doc` mode:
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```
Equivalent shell command:
```bash
cmd1 << LIMITER | cmd2 >> outfile
```

## Resources
Classic references used for this project:
- Linux man pages: `man 2 open`, `man 2 pipe`, `man 2 fork`, `man 2 dup2`, `man 2 execve`, `man 2 waitpid`, `man 2 access`
- The Linux Programming Interface (Michael Kerrisk)
- 42 subject PDF and peer evaluation guidelines

### AI usage disclosure
AI was used as a coding assistant for:
- reviewing error-handling behavior compared to shell-like expectations
- identifying edge cases for command resolution and exit codes
- improving README structure and clarity

All implementation decisions, integration, and final validation were performed in the project repository.