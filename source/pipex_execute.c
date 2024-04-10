/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:39:37 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/09 14:37:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
* @brief Execute the command line with the arguments
* @param cmd_str the str of command with the paramethers. Ex - "wc -l".
* @param envp envp variables.
* @return Execute the command. If not, clean everything. 
*/
void	execute_cmd(char *cmd_str, char **envp)
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
	exit(EXIT_FAILURE);
}

/**
 * @brief Find "PATH" in the environment variable.
 * @param envp Environment variable.
 * @return Line that start with PATH from the envp.
 */
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

/**
 * @brief Return the join from possible_path and command with an /
 * @param possible_char Char with a possible path
 * @param command Command that is appended to end
 * @return A possible path to be used in execve();
*/
char	*create_cmdpath(char *possible_path, char *command)
{
	char	*path;
	char	*temp;

	temp = ft_strjoin(possible_path, "/");
	path = ft_strjoin(temp, command);
	free(temp);
	return (path);
}
