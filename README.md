# 42_pipex - Repository under construction

![Banner](libft.png "libft banner")

"This project is about handling pipes..."

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [First things first](#first-things-first)
- [Explanation](#Explanation)
- [Bonus](#bonus)
- [Makefile Overview](#makefile-overview)
- [License and glorious advice](#license-and-glorious-advice)

## Introduction
Pipex is a project about file descriptors redirections, process management, executing commands and pipes. :blush: <br>
This project presents some new concepts that we havent seen until now: processes, file descriptor redirection and pipes.
To understand better what are the requirements of this project, see the *subject*
> This project's code was written according to the *42 norm guidelines(norminette)*.

## Usage

To use the library in your project, follow these steps:
1. Clone the repository
```bash
git clone git@github.com:amauricoder/42_Pipex.git
```

2. Do make to compile the files
```bash
make
```

This will generate the pipex file in the root folder, that is executable of the program.
3. Create and infile and write some information inside.
``bash
touch infile
vim infile
``

4. execute the program with the following paramethers
```bash
./pipex infile "cmd1" "cmd2" outfile
```

Where
* infile - Its the infile for the project.
* cmd1 - Its the first command that will be redirected from the infile to the pipe
* cmd2 - Its the second command that will be redirected from the pipe to the outfile
* outfile - its the file that will receive the commands

Examples:
```bash
- ./pipex infile "ls -l -a -h -G -r -R" "wc -l" outfile
```
```bash
- ./pipex infile "sed s/a/A/g" "wc -c" outfile
```
```bash
- ./pipex infile "tail -n 5" "grep pattern" outfile
```
## First things first
First of all, I would like to thank the people who gave time and energy to construct incredible articles and videos about file descriptors redirection, forks, pipes, executions, processes, and C programming in general. Thank you very much!
Here are some of the sources that I used to understand the concepts behind everything in this project:

- [Pipe: An Inter-Process Communication Method ](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/?source=post_page-----71984b3f2103) By [Mia Combeau.](https://www.codequoi.com/en/home-english/)
- [Youtube playlist by CodeVault](https://www.youtube.com/watch?v=2hba3etpoJg&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=9) By [Code Vault.](https://www.youtube.com/@CodeVault)
- [Pipes, Forks, and Dups](https://www.rozmichelle.com/pipes-forks-dups/) By [Roslyn Michelle Cyrus McConnell](https://www.rozmichelle.com/)
- [Pipex Tutorial: 42 Project ](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901) By [zihan](https://csnotes.medium.com/)
- [A Comprehensive Guide to Pipex ](https://reactive.so/post/42-a-comprehensive-guide-to-pipex) By [herbievine](https://reactive.so/)

Thank you very much for the contribution to the community.

## Explanation
***Important!*** <br>
To understand how this project works, we need to understand some important concepts. I will explain some of these concepts in a very concise way below. I do recommend for you to read the articles and watch the videos above for a better and deeper understanding.

- *Processes:* Are instances of a program. They have their own memory scope. A program can have multiple processes running in parallel at the same time.
- *Pipes:* Pipes are spaces in memory that allow two processes to communicate with each other in an efficient way. They have file descriptors to read information and to write.
- *File Descriptors:* Are numbers used by a computer to identify open files. They're like labels for files, allowing programs to read from and write to them. For example, stdin (0), stdout (1), and stderr (2) are standard descriptors for input, output, and error streams, respectively.
- *STDIN_FILENO and STDOUT_FILENO:* Are macros for the standard read and write file descriptors from the terminal. They are defined in <unistd.h>.

This project basically creates a process for the first command. For this specific process, it redirects the STDIN_FILENO to the infile and STDOUT_FILENO to the write side of the pipe, through the dup2() function. And then, it executes the command. When the command is executed, the process ends. This means that for the first command, it will read information from the input file, and after executing, the output will be sent to the pipe.
For the second command, the process that will be responsible is the parent process. It redirects the STDOUT_FILENO to the outfile, and the STDIN_FILENO to the read side of the pipe. And then, it executes the command. This means that for the second command, it will read the information that is inside the pipe, execute the command with this information, and will redirect the information to the outfile.
## Bonus
### Bonus explanation ###
For the bonus part, we needed to reproduce the behaviour of here_doc and the behaviour of a pipeline. A pipeline is basically works with more than 1 pipe. For more informations, see the *subject*.
The bonus part is a little more complicated than the main project.
Basically, we need to check if we have here_doc, if we have we will receive the information and here_doc will replace the infile. Then, we needed to create a process for every command(except for the last, that will be treated for the main process).
The logic of redirection is basically the same as in the main project, but here we will redirect from one pipe to another inside the loop.

## Makefile Overview

In this project, the Makefile offers the following essential rules:

- **make**: Compiles the main project to `pipex` executable.

- **make clean**: Cleans the directory by removing `.o` files, preserving `pipex` executable.

- **make fclean**: Completely cleans the directory by deleting both `.o` files and `pipex` executable.

- **make re**: Refreshes `pipex` by recompiling everything.

Additionally:

- **make bonus**: Compiles the bonus project to `pipex_bonus` executable.
- **make bre**: Refreshes the `pipex_bonus` by recompiling everything.

## License and glorious advice
[View License](LICENSE)

I strongly recommend to 42 students who are searching for resources to avoid using CTRL+C CTRL+D, as this is the cornerstone of all upcoming projects. 
Don't use any code that you can't reconstruct from scratch and/or don't understand. 
The lack of knowledge will become a significant problem over time. 
Good luck!

