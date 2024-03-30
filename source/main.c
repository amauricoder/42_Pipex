/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:31:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/30 14:29:10 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//Project Overview
//The parent process should be responsible for executing cmd2 and 
//reading its input from the pipe.

//child - The child process should be responsible for executing cmd1 and 
//writing its output to the pipe. 

//Execute commands using execve.
//execve(const char *pathname, char *const argv[], char *const envp[])
//execve(cmd, cmd_args, envp);

//arguments -> file1 cmd1(childp) cmd2(parentp) file2
int	main(int argc, char **argv, char **envp)
{
	t_pstruct	pipex;

	pipex = (t_pstruct){0};
	if (!(arg_isvalid(argc, argv)) || pipe(pipex.pipefd) == -1)
	{
		write(2, "Error\nInvalid Arguments or Pipe error\n", 39);
		exit(EXIT_FAILURE);
	}
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_management("Error\nFork ():");
	if (pipex.pid == 0)
	{
		redirect_childfd(argv, pipex);
		execute_cmd(argv[2], envp);
	}
	wait(NULL);
	redirect_parentfd(argv, pipex);
	execute_cmd(argv[3], envp);
	return (0);
}
