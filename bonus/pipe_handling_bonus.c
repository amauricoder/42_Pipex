/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:46:16 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 09:23:09 by aconceic         ###   ########.fr       */
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
	while (i < bonus_data->processes - 1)
	{
		if (pipe(bonus_data->pipesfd_arr[i]) == -1)
		{
			perror("Pipe : ");
			exit(EXIT_FAILURE);
		}
		i ++;
	}
}
/**
 * @brief Creates arr for the pids
 * @param bonus_data struct with data from bonus
 * @param i itineration variable
 * @return error with perror or EXIT_SUCCESS
*/
int	fork_arr(t_pipexbn *bonus_data, int i)
{
	bonus_data->pid_arr[i] = fork();
	if (bonus_data->pid_arr[i] == -1)
		perror("Error\nfork_arr() ");
	return (EXIT_SUCCESS);
}

void	input_to_pipe(t_pipexbn *bonus_data)
{
	close(bonus_data->pipesfd_arr[0][0]);
	if (dup2(bonus_data->infile, STDIN_FILENO) == -1)
		error_management("Error\ninput_to_pipe");
	if (dup2(bonus_data->pipesfd_arr[0][1], STDOUT_FILENO) == -1)
		error_management("Error\ninput_to_pipe");
	close(bonus_data->infile);
	close(bonus_data->pipesfd_arr[0][1]);
	return ;
}

void pipe_to_pipe(t_pipexbn *d, int i)
{
	ft_printf("valor de i %i\n", i);
	int j = 0;
	
	while (d->pipesfd_arr[j])
	{
		ft_printf("fd[%i][0] -> %i\n", j, d->pipesfd_arr[j][0]);
		ft_printf("fd[%i][1] -> %i\n", j, d->pipesfd_arr[j][0]);
		j ++;
	}
    if (dup2(d->pipesfd_arr[i - 1][1], STDIN_FILENO) == -1
	|| dup2(d->pipesfd_arr[i][1], STDOUT_FILENO) == -1)
    {
        perror("dup2");
    	exit(EXIT_FAILURE);
    }
    close(d->pipesfd_arr[i - 1][1]);
    close(d->pipesfd_arr[i][1]);
}

void	output_to_pipe(t_pipexbn *bonus_data)
{
	int	output_fd = bonus_data->outfile;
	close(bonus_data->pipesfd_arr[qt_pipes(bonus_data) - 1][1]);
	if (dup2(bonus_data->pipesfd_arr[qt_pipes(bonus_data) - 1][0], STDIN_FILENO) == -1
		|| dup2(output_fd, STDOUT_FILENO) == -1)
		error_management("Error\nOutput_to_pipe");
	close(output_fd);
	close(bonus_data->pipesfd_arr[qt_pipes(bonus_data) - 1][0]);
	return ;
}