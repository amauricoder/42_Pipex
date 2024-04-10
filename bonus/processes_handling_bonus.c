/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_handling_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:00:46 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/09 11:06:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Create Pipe, create process, redirect pipe fds and exec.\n
 * For child -> redirect out of pipe to STDOUT_FILENO and exec.\n
 * For parent -> close write of pipe. redirect in of pipe do STDIN and wait for
 * child to end to itinerate again. (function goes within a loop).
 * @param d struct with the data for the project
 * @param i itinerable variable, to set position of cmd
 * @param argv argument vector
 * @param envp enviroment variables
*/
void	process_rdrct_and_exec(t_data *d, int i, char **argv, char **envp)
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
		execute_cmd_bonus(d, argv[2 + i + d->is_heredoc], envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

/**
* @brief Execute the command line with the arguments
* @attention The diffecente from this one to the main one is that this
* cleans the structure of bonus in case of error
* @param cmd_str the str of command with the paramethers. Ex - "wc -l".
* @param envp envp variables.
* @return Execute the command. If not, clean everything. 
*/
void	execute_cmd_bonus(t_data *bonus_data, char *cmd_str, char **envp)
{
	char	**cmd_withargs;
	char	**possible_paths;
	char	*path_line;
	char	*path;
	int		i;

	cmd_withargs = cmd_handling(cmd_str);
	path_line = find_execpath(envp);
	possible_paths = ft_split(path_line, ':');
	i = 0;
	while (possible_paths[i] != NULL)
	{
		path = create_cmdpath(possible_paths[i], cmd_withargs[0]);
		if (access(path, X_OK) != -1)
			execve(path, cmd_withargs, envp);
		free(path);
		i ++;
	}
	write (2, "Error\n", 7);
	perror(cmd_withargs[0]);
	free_execute_cmd(cmd_withargs, possible_paths);
	free(bonus_data);
	exit(EXIT_FAILURE);
}
