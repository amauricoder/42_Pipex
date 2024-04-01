/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:58:31 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/01 19:38:28 by aconceic         ###   ########.fr       */
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
