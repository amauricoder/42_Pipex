/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:49:55 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 19:34:53 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
* @brief Verify the arguments are valid
* @param argc arguments counter.
* @param argv arguments vector".
* @return 1 for true(valid) - 0 for false(invalid)
*/
int	arg_isvalid_bonus(int argc, char **argv)
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
	if (argc < 5)
		return_value = 0;
	return (return_value);
}

/**
 * @brief Initialize and allocate memory for struct of pipex bonus
 * @attention Allocate memory.
 * @param argc
 * @param argv
 * @return The struct with values initialized
*/
t_pipexbn	*init_bonus_struct(int argc, char **argv)
{
	t_pipexbn	*bonus_data;

	bonus_data = ft_calloc(sizeof(t_pipexbn), 1);
	if (!bonus_data)
		return (NULL);
	if (!ft_strcmp(argv[1], "here_doc"))
		bonus_data->is_heredoc = 1;
	else
		bonus_data->is_heredoc = 0;
	bonus_data->processes = (argc - 3) - bonus_data->is_heredoc;
	return (bonus_data);
}

/**
 * @brief Display an error message to fd2 and exit the program with EXIT_FAILURE
 * @param message The message to be displayed;
 */
void	error_message(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}


