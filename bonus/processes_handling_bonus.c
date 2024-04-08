/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_handling_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:00:46 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 21:48:46 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Create Pipe, create process, if is child -> redirect 
 * @param d struct with the data for the project
 * @param i itinerable variable, to set position of cmd
 * @param argv argument vector
 * @param envp enviroment variables
*/
void	process_redirect_and_exec(t_pipexbn *d, int i, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		error_management("Error\nPipe");
	pid = fork();
	if (pid == -1)
		error_management("Erro fork()");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_cmd(argv[2 + i + d->is_heredoc], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}
