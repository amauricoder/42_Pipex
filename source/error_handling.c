/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:12:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/26 11:17:36 by aconceic         ###   ########.fr       */
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
