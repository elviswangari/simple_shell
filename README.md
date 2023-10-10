
# Simple Shell version 2

We are going to cover how to implement a  simple shell in c programming language

before getting started well look at some few things

## refresher

[refresher](./refresher) => in this directory we create files containing what we will require for the shell project

compiling the c file(change filename and output to your desired ones)

```
gcc -Wall -Wextra -Werror -pedantic <filename>.c -o <output>
```

1. [pid](./refresher/1_pid.c) =>  checks for both child and  parent pid using the `getpid` and `getppid` functions respectivly. The parent pid should be same each time you run the program but the child process changes each time

2. [args](./refresher/2_args.c) => take args from the commandline then prints them out by only using the args vector
3. [readline](./refresher/3_readline.c) => we use readline to check the characters that were typed by the user then we print them out
4. [tokenization](./refresher/4_split_line.c) => we use strtok to split and print all the tokens provided based on the delimiters provided
