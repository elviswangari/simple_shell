
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

### File information

11. [stat](./refresher/11_stat.c) => using stat function in c to get information about an object or a file (which)

#### 3. implement which

12. [which](./refresher/12_which.c) => simple implementation of (which) which gives info about a certain file using the stat function

### Environment

Each process comes with an environment and we can use `printenv` to show all the environment variables available

we know that when a process is created the child process inherits a copy of the parents environment

to access the environment within a process we can can use the 3 prototypes of main

#### main

    a) int main(void);
    b) int main(int ac, char **av);
    c) int main(int ac, char **av, char **env); -> where env is a null terminated array of string and it accualy represent the environment
13. [printenv](./refresher/13_printenv.c) => using the third main prototype to print out the environment

### Exercises

#### printenv with environ

Write a program that prints the environment using the global variable environ.

14. [environ](./refresher/14_environ.c) => environ is a global valiable that is usually define as an external variable which prints out each present environment

#### env vs environ

Write a program that prints the address of env (the third parameter of the main function) and environ (the global variable).

15. [env vs environ](./refresher/15_env&&environ.c) => from the output of the above file it means they are one and the same thing as the addresses are the same

#### getenv()

Write a function that gets an environment variable. (without using getenv)

Prototype: `char *_getenv(const char *name);`

##### what is getenv

getenv is a function that retreaves the values of environment variables which takes in a pointer as an argument and returns the value if found returns null

16. [getenv](./refresher/16_getenv.c) => a custom getenv function

#### a fuction to print out the paths of environments

Write a function that prints each directory contained in the the environment variable PATH, one directory per line.

17. [path](./refresher/17_path.c) => prints out the path of each environ

#### a function to create a linked list of the paths

Write a function that builds a linked list of the PATH directories.

18. [linked list paths](./refresher/18_linkedpaths.c) => creates linked lists of the paths
