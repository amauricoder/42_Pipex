/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:31:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/26 10:13:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

	if (argc != 5 || pipe(pipex.pipefd) == -1)
		error_management(1);
	pipex.pid = fork();
	if (pipex.pid == -1)
		error_management(2);
	if (pipex.pid == 0)
	{
		redirect_childfd(argv, pipex);
		execute_cmd(argv[2], envp, pipex);
	}
	wait(NULL);
	redirect_parentfd(argv, pipex);
	execute_cmd(argv[3], envp, pipex);
	return (0);
}
