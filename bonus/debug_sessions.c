/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sessions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:52:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/05 16:02:41 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int qt_pipes(t_pipexbn *bonus_data)
{
    int i = 0;
	while (bonus_data->pipesfd_arr[i])
	{/* 
        ft_printf("------\n");
		ft_printf("pipe %i \n", i);
        ft_printf("------\n");
		ft_printf("fd in %i \n", bonus_data->pipesfd_arr[i][0]);
		ft_printf("fd in %i \n", bonus_data->pipesfd_arr[i][1]); */
		i ++;
	}
    return (i);
}




//./pipex_bonus here_doc limiter cmd1 cmd2 output.txt
//./pipex_bonus input.txt cmd1 cmd2 output.txt
//./pipex_bonus input.txt "cat" "wc -l" output.txt
//./pipex_bonus input.txt "ls -l" "wc -l" output.txt
//./pipex_bonus here_doc EOF "cat" "wc -l" output.txt
//pipefd[0]: the read end
//pipefd[1]: the write end