/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:31:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/09 12:11:31 by aconceic         ###   ########.fr       */
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
		if (pipex.pid == -1)
		{
			ft_printf("error fork() line 29");
		}

		if (pipex.pid != 0)
		{
			//The parent process should be responsible for executing cmd2 and 
			//reading its input from the pipe. Ensure you close the appropriate
			//file descriptors (pipefd[1]) before reading from the pipe.
			int	output_fd;
	
			output_fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0755);
			if (output_fd < 0)
			{
				//treat this error descently
				ft_printf("Error line 45\n");
			}
			close(pipex.pipefd[1]); // clse write end of file
			//Redirect stdin to read from the read end of the pipe (pipefd[0]).
			//Redirect stdout to write to the output file.
			if (dup2(pipex.pipefd[0], STDIN_FILENO) == -1 || dup2(output_fd, STDOUT_FILENO) == -1)
			{
				ft_printf("Error dup2 line 35.\n");
			}
			close(output_fd);
			close(pipex.pipefd[0]);
   			//Execute cmd2 using execve.
		}
		else
		{
			//child - The child process should be responsible for executing cmd1 and 
			//writing its output to the pipe. Ensure you close the appropriate file 
			//descriptors (pipefd[0]) after writing to the pipe.
			int	input_fd;

			input_fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0755);
			if (input_fd < 0)
			{
				//treat this error descently
				ft_printf("Error line 69\n"); 
			}
			close(pipex.pipefd[0]); // close read end of file
			//Redirect stdin to read from the input file.
    		//Redirect stdout to write to the write end of the pipe (pipefd[1]).
			if (dup2(pipex.pipefd[1], STDOUT_FILENO) == -1 || dup2(input_fd, STDIN_FILENO) == -1)
			{
				ft_printf("Error dup2 line 50.\n");
			}
			close(input_fd);
			close(pipex.pipefd[1]);
    		//Execute cmd1 using execve.
		}
	}
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