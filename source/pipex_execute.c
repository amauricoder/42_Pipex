/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:39:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/26 13:37:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//Execute the command line with the arguments
void	execute_cmd(char *cmd_str, char **envp)
{
	char	**cmd_withargs;
	char	**possible_paths;
	char	*path_line;
	char	*path;
	int		i;

	cmd_withargs = ft_split(cmd_str, ' ');
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
	write (2, "Error\n", 6);
	perror(cmd_withargs[0]);
	free_execute_cmd(cmd_withargs, possible_paths);
	exit(EXIT_FAILURE);
}

char	*find_execpath(char **envp)
{
	char	*path;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i ++;
	path = envp[i];
	return (path);
}

char	*create_cmdpath(char *possible_path, char *command)
{
	char	*path;
	char	*temp;

	temp = ft_strjoin(possible_path, "/");
	path = ft_strjoin(temp, command);
	free(temp);
	return (path);
}
