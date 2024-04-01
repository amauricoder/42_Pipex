/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/01 19:57:19 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

//./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
//< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

// ./pipex here_doc LIMITER cmd cmd1 file
// cmd << LIMITER | cmd1 >> file
int main(int argc, char **argv, char **envp)
{
	t_pipexbn *bonus_data;
	int	i;

	if (!arg_isvalid_bonus(argc, argv) || !envp || envp[0][0] == '\0')
	{
		write(2, "Error\nInvalid arguments or not envp", 36);
		exit(EXIT_FAILURE);
	}
	ft_printf("Function is running\n"); // for debug purpose
	bonus_data = init_bonus_struct(argc, argv);
	//separate fds to pipe() for every child;
	bonus_data->pipesfd = alloc_pipes(bonus_data);

	//we need to create a pipe (a pair of file descriptors) 
	//for each child process.
	i = 0;
	while (i < bonus_data->processes)
	{
		//fork
		//execute here
		ft_printf("fd[] => %i, %i\n", bonus_data->pipesfd[i][0], bonus_data->pipesfd[i][1]);
		i ++;
	}
	
	(void)envp;

}