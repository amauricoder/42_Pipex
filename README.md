# 42_pipex - Repository under construction

![Banner](libft.png "libft banner")

"This project is about handling pipes..."

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [First Part](#first-part)
- [Second Part](#second-part)
- [Bonus](#bonus)
- [Makefile Overview](#makefile-overview)
- [License and glorious advice](#license-and-glorious-advice)

## Introduction
Pipex is a project about file descriptors redirections, process management, executing commands and pipes. :blush:

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

3. execute the program with the following paramethers
```bash
./pipex infile "cmd1" "cmd2" outfile
```
Where
* infile - Its the infile for the project.
* cmd1 - Its the first command that will be redirected from the infile to the pipe
* cmd2 - Its the second command that will be redirected from the pipe to the outfile
* outfile - its the file that will receive the commands

## First things first
First of all, I would like to thanks for the people who gave time and energy to construct incredible articles and videos about file descriptors redirection, forks, pipes, executions, processes and C programming in general. Thank you very much!
Here are some of the sources that I used to understand the concepts about everything of this project.

- https://www.codequoi.com/en/pipe-an-inter-process-communication-method/?source=post_page-----71984b3f2103 - By Mia Combeau.
- https://www.youtube.com/watch?v=2hba3etpoJg&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=9 - By Code Vault.
- https://www.rozmichelle.com/pipes-forks-dups/ - By Roslyn Michelle Cyrus McConnell
- https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901 - By zihan
- https://reactive.so/post/42-a-comprehensive-guide-to-pipex - By herbievine

  Thank you very much for for the contribuition for the community.
<!--
## Second Part

The subsequent phase focuses on the development of a set of functions, either absent in the libc or presented in a different form. To explore the comprehensive list of functions in this section, check the [Subject](subject/1-libft.pdf).

## Bonus

For the bonus segment of the project, you will construct functions capable of manipulating lists. For a more detailed understanding of the functions in the bonus part, please consult the [Subject](subject/1-libft.pdf).

## Makefile Overview

In this project, the Makefile offers the following essential rules:

- **make**: Compiles the primary and secondary functions into `libft.a`.

- **make clean**: Cleans the directory by removing `.o` files, preserving `libft.a`.

- **make fclean**: Completely cleans the directory by deleting both `.o` files and `libft.a`.

- **make re**: Refreshes `libft.a` by recompiling everything.

Additionally:

- **make bonus**: Incorporates bonus functions into `libft.a`.

## License and glorious advice
[View License](LICENSE)

I strongly recommend to 42 students who are searching for resources to avoid using CTRL+C CTRL+D, as this is the cornerstone of all upcoming projects. 
Don't use any code that you can't reconstruct from scratch and/or don't understand. 
The lack of knowledge will become a significant problem over time. 
Good luck!
-- >
