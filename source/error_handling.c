/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:12:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/26 13:30:28 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_management(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_execute_cmd(char **cmd_arg, char **pp)
{
	int	i;

	i = 0;
	while (cmd_arg[i] != NULL)
	{
		free(cmd_arg[i]);
		i ++;
	}
	free(cmd_arg);
	i = 0;
	while (pp[i] != NULL)
	{
		free(pp[i]);
		i ++;
	}
	free(pp);
}

int	arg_isvalid(int argc, char **argv)
{
	int	i;
	int	return_value;

	return_value = 1;
	i = 0;
	while (argv[i])
	{
		if (!argv[i] || !ft_strcmp(argv[i], ""))
		{
			return_value = 0;
			break ;
		}
		i ++;
	}
	if (argc != 5)
		return_value = 0;
	return (return_value);
}
