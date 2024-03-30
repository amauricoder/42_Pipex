/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:12:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/30 19:35:03 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
* @brief Send a message with perror() and exit with EXIT_FAILURE macro
* @param msg str to be sended.
*/
void	error_management(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

/**
* @brief Free strs and arrays from execute_cmd()
* @param cmd_arg arr to be cleaned.
* @param pp str to be cleaned".
*/
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

/**
* @brief Verify the arguments are valid
* @param argc arguments counter.
* @param argv arguments vector".
* @return 1 for true(valid) - 0 for false(invalid)
*/
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
