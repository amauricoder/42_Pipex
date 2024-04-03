/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:54:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/03 10:48:17 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
* @brief Clean the cmd_arr from cmd_handling
* @param cmd_arr char_arr to be cleaned.
*/
static void	free_cmd_arr(char **cmd_arr)
{
	int	i;

	i = 0;
	while (cmd_arr[i])
		free(cmd_arr[i ++]);
	free(cmd_arr);
}

/**
* @brief Handle with ' ' and " " that can be found in some commands
* @param cmd_complete the str of command with the paramethers. 
	Ex - "awk '{count++} END {print count}'".
* @return An array with the command and the paramethers. 
	arr[0] = "awk" arr[1]; = "{count++} END {print count}"; arr[2] = "NULL"
*/
char	**cmd_handling(char *cmd_complete)
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
	{
		free(cmd_only);
		return (ft_split(cmd_complete, ' '));
	}
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
