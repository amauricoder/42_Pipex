/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:49:55 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 12:00:35 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
	bonus_data->pipesfd_arr = alloc_pipefds(bonus_data->processes);
	bonus_data->pid_arr = alloc_pids(bonus_data->processes);
	return (bonus_data);
}

/**
 * @brief Alloc necessary amount of space for the pipes on the struct
 * @attention Allocates memory
 * @param processes_qt Quantity of processes of the project
 * @return double pointer with memory allocated
*/
int	**alloc_pipefds(int processes_qt)
{
	int	**pipes_fd;
	int	i;

	pipes_fd = ft_calloc(sizeof(int *), processes_qt);
	if (!pipes_fd)
		return (NULL);
	i = 0;
	while (i < processes_qt - 1)
	{
		pipes_fd[i] = ft_calloc(2, sizeof(int));
		if (!pipes_fd[i])
		{
			free(pipes_fd);
			return (NULL);
		}
		i ++;
	}
	return (pipes_fd);
}

/**
 * @brief Alloc necessary amount of space for the pids of the project
 * @attention Allocates memory
 * @param processes_qt Quantity of processes of the project
 * @return A pointer with memory allocated
*/
int	*alloc_pids(int processes_qt)
{
	int	*pid_toalloc;

	pid_toalloc = ft_calloc(sizeof(int), processes_qt - 1);
	if (!pid_toalloc)
		return (NULL);
	return (pid_toalloc);
}
