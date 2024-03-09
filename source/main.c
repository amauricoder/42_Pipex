/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:31:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/09 10:59:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//arguments -> file1 cmd1(childp) cmd2(parentp) file2
int main(int argc, char **argv, char **envp)
{
	t_pstruct pipex;

	if (argc != 5 || pipe(pipex.pipefd) == -1)
	{
		ft_printf("Erro aqui nos argumentos ou no pipe campeao\n");
		//errors treatment. needs to treat descently not with a fk printft.
	}
	else
	{
		ft_printf("Argumentos e pipe ok;\n");
		pipex.pid = fork();
		if (pipex.pid != 0)
		{
			//The parent process should be responsible for executing cmd2 and 
			//reading its input from the pipe. Ensure you close the appropriate
			//file descriptors (pipefd[1]) before reading from the pipe.

			//need function to
			//redirect the stdin from the read end of the pipe and
		 	//the stdout to the output file
			//output(char **argv[5], char **envp)

			//Redirect stdin to read from the read end of the pipe (pipefd[0]).
    		//Redirect stdout to write to the output file.
   			//Execute cmd2 using execve.
			
		}
		else
		{
			//child - The child process should be responsible for executing cmd1 and 
			//writing its output to the pipe. Ensure you close the appropriate file 
			//descriptors (pipefd[0]) after writing to the pipe.
		
			//need function to 
			//redirect the stdin from the input file and
		 	//the stdout to the write end of the pipe;
			//construc function input_redirect(char **argv[1], char **envp);

			//Redirect stdin to read from the input file.
    		//Redirect stdout to write to the write end of the pipe (pipefd[1]).
    		//Execute cmd1 using execve.
		}
	}
	(void)argv;
	(void)envp;
	//close() to close the pipe
	return (0);
}

//Input and Output Redirection: You mentioned the need for functions
//to handle input and output redirection. These functions should handle 
//file descriptor manipulation using dup2 to redirect standard input/output 
//to files or pipes as needed.

//Error Handling: Ensure proper error handling for system calls like fork, 
//pipe, execve, etc. This will help in diagnosing issues during program execution.