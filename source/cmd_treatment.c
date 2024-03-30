/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treatment2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:54:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/30 19:12:00 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//clean this specific arr
static void	free_cmd_arr(char **cmd_arr)
{
	int	i;

	i = 0;
	while (cmd_arr[i])
		free(cmd_arr[i ++]);
	free(cmd_arr);
}

//"awk '{count++} END {print count}'"
//awk '"{count++} END {print count}"'
//clean the argument if have '' or ""
//and join with the command
//return a double pointer with the arr cleaned
char	**cmd_handling2(char *cmd_complete)
{
	char	**cmd_arr;
	char	*cmd_only;
	char	*arg_only;

	cmd_arr = ft_split(cmd_complete, ' ');
	cmd_only = ft_strdup(cmd_arr[0]);
	free_cmd_arr(cmd_arr);
	arg_only = ft_strchr(cmd_complete, 39);
	if (arg_only == NULL)
		arg_only = ft_strchr(cmd_complete, 34);
	if (arg_only == NULL)
		return (ft_split(cmd_complete, ' '));
	else
	{
		cmd_arr = malloc(sizeof(char *) * 3);
		if (!cmd_arr)
			return (NULL);
		cmd_arr[0] = cmd_only;
		cmd_arr[1] = ft_strtrim(arg_only, "'");
		cmd_arr[2] = NULL;
		return (cmd_arr);
	}
}
