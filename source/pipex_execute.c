/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:39:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/26 10:14:51 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_cmd(char *cmd_str, char **envp, t_pstruct pipex)
{
	char	**cmd_withargs;
	char	**possible_paths;
	char	*path_line;
	char	*path;
	int		i;
	//dont forget to make frees()
	cmd_withargs = ft_split(cmd_str, ' ');
	path_line = find_execpath(envp);
	possible_paths = ft_split(path_line, ':');
	i = 0;
	while (possible_paths[i] != NULL)
	{
		path = ft_strjoin(possible_paths[i], ft_strjoin("/", cmd_withargs[0]));
		if (access(path, X_OK) == -1)
		{
			i ++;
			free(path);
		}
		else
			execve(path, cmd_withargs, envp);
	}
	(void)pipex;
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
