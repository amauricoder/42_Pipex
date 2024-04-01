/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:46:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/01 19:53:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Alloc necessary amount of space for the pipes on the struct
 * @attention Allocates memory
 * @param argc
 * @param argv
 * @param bonus_data struct containing values for the project
 * @return double pointer with memory allocated
*/
int	**alloc_pipes(t_pipexbn *bonus_data)
{
	int **pipes_fd;
	int	i;

	pipes_fd = ft_calloc(sizeof(int *), bonus_data->processes);
	if (!pipes_fd)
		return (NULL);
	i = 0;
	while (i < bonus_data->processes)
	{
		pipes_fd[i] = ft_calloc(2, sizeof(int));
		if (!pipes_fd[i])
		{
			//here i need to clean properly
			free(pipes_fd);
			return (NULL);
		}
		i ++;
	}
	return (pipes_fd);
}