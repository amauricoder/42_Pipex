/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:28:00 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/03 15:41:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void    free_pipexbn_struct(t_pipexbn *bonus_data)
{
    int i;

    i = 0;
	while(i < bonus_data->processes)
	{
		free(bonus_data->pipesfd_arr[i]);
		i ++;
	}
	free (bonus_data->pipesfd_arr);
	
	i = 0;
	free(bonus_data->pid_arr);
	free(bonus_data);
}

void	error_message(char *message)
{
	write(2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}