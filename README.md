
# Simple Shell version 2

We are going to cover how to implement a  simple shell in c programming language

before getting started well look at some few things

## refresher

[refresher](./refresher) => in this directory we create files containing what we will require for the shell project

compiling the c file(change filename and output to your desired ones)

```
gcc -Wall -Wextra -Werror -pedantic <filename>.c -o <output>
```

### Pid && ppid

1. [pid](./refresher/1_pid.c) =>  checks for both child and  parent pid using the `getpid` and `getppid` functions respectivly. The parent pid should be same each time you run the program but the child process changes each time

### Arguments

2. [args](./refresher/2_args.c) => take args from the commandline then prints them out by only using the args vector
3. [readline](./refresher/3_readline.c) => we use readline to check the characters that were typed by the user then we print them out
4. [tokenization](./refresher/4_split_line.c) => we use strtok to split and print all the tokens provided based on the delimiters provided

### Executing a program

5. [execution](./refresher/5_exec.c) => we use execve to execute programs. it take in 3 parameters filename or path, array of argument list, current environment or null(best to add the environ)

### Creating a process

6. [fork](./refresher/6_fork.c) => we create a new process from the parent using `fork`
7. [fork return value](./refresher/7_fork.c) => from the return value of `fork` we can get which process is being called at the moment
8. [wait](./refresher/8_wait.c) => the wait function allows us to wait for a child process to finish so that the parent can sync or perform other opperations

### Exercise

#### 1. fork + wait + execve

Write a program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.

9. [fork wait exec](./refresher/9_forwaitexec.c) => a quick exercise for creating 5 processes making sure that the parent waits for one child to finish execution before creating another child

#### 2. super simple shell

Using everything we saw, write a first version of a super simple shell that can run commands with their full path, without any argument.
10. [fork wait exec](./refresher/10_supersimpleshell.c) => creating a super simple shell that lists files
