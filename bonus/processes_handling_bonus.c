/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_handling_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:00:46 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/05 14:37:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int child_process(t_pipexbn *bonus_data, int i, char **argv, char **envp)
{
	
    execute_cmd(argv[2 + bonus_data->is_heredoc + i], envp);
    return (EXIT_SUCCESS);
}

int parent_process(t_pipexbn *bonus_data, char **argv, char **envp)
{
   
    execute_cmd(argv[bonus_data->processes + 1 + bonus_data->is_heredoc], envp);
	return (EXIT_SUCCESS);
}