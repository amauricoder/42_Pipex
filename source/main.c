/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:31:48 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/09 09:48:01 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//arguments -> file1 cmd1 cmd2 file2
//fd[0] read
//fd[1] write
int main(int argc, char **argv, char **envp)
{
	t_pstruct pipex;

	(void)argv;
	
	
	if (argc != 5 || pipe(pipex.pipefd) == -1)
	{
		ft_printf("argc error or pipe error\n");
		return (0);	
	}

	//The question is that the shell creates a pipe for each command.
	
	//close() to close the pipe
	return (0);
}
