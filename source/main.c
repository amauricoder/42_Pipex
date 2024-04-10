/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:31:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/09 14:30:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * @brief init struc with values with 0, check valicity of arguments,
 * do 1 fork. to redirection to pipe and execute projects.
*/
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
