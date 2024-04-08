/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 12:12:27 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

//./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
//< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

// ./pipex here_doc LIMITER cmd0 cmd1 file
// cmd << LIMITER | cmd1 >> file
int	main(int argc, char **argv, char **envp)
{
	t_pipexbn	*bonus_data;
	int			i;
	int			fd[2];
	int			pid;

	if (!arg_isvalid_bonus(argc, argv) || !envp || envp[0][0] == '\0')
		error_message("Error\nInvalid arguments or empty envp");
	bonus_data = init_bonus_struct(argc, argv);
	open_infile(argv, bonus_data);
	open_outfile(bonus_data, argc, argv);
//	create_pipes(bonus_data);
	i = 0;
	while (i < bonus_data->processes - 1)
	{
		if (pipe(fd) == -1)
			error_management("erro pipe()");
		pid = fork();
		if (pid == -1)
			error_management("Erro fork()\n");
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			execute_cmd(argv[2 + i + bonus_data->is_heredoc], envp);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			waitpid(pid, NULL, 0);
		}
		i ++;
	}
	dup2(bonus_data->outfile, STDOUT_FILENO);
	execute_cmd(argv[argc - 2], envp);
	free_pipexbn_struct(bonus_data);
	return (0);
}