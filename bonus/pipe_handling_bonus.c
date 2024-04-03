/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:46:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/02 17:53:02 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Creates the pipes and allocate the fd to the pipesfd arrray in the struct
 * @attention Allocates memory
 * @param bonus_data struct of the bonus
*/
void	create_pipes(t_pipexbn *bonus_data)
{
	int	i;

	i = 0;
	while (i < bonus_data->processes)
	{
		if (pipe(bonus_data->pipesfd_arr[i]) == -1)
		{
			//Dont forget to clean the struct in case of error.
			perror("Pipe : ");
			exit(EXIT_FAILURE);
		}
		i ++;
	}
}
