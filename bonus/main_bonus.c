/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/07 00:14:55 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

//./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
//< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

// ./pipex here_doc LIMITER cmd0 cmd1 file
// cmd << LIMITER | cmd1 >> file
int main(int argc, char **argv, char **envp)
{
	t_pipexbn	*bonus_data;
	int			i;

	if (!arg_isvalid_bonus(argc, argv) || !envp || envp[0][0] == '\0')
		error_message("Error\nInvalid arguments or empty envp");
	bonus_data = init_bonus_struct(argc, argv);
	open_infile(argv, bonus_data);
	open_outfile(bonus_data, argc, argv);
	create_pipes(bonus_data);

	//ft_printf("Qt of processes %i\n", bonus_data->processes);
	//ft_printf("\n");
	i = 0;
	while(i < bonus_data->processes - 1)
	{
		if (fork_arr(bonus_data, i) == -1)
			perror("fork arr");
		if (bonus_data->pid_arr[i] == 0)
		{
			if (i == 0)
			{
				input_to_pipe(bonus_data);
				execute_cmd(argv[2 + bonus_data->is_heredoc], envp);
				return (0);
			}
			else
			{
				pipe_to_pipe(bonus_data, i);
				execute_cmd(argv[2 + i + bonus_data->is_heredoc], envp);
				return (0);
			}
		}
		i ++;
	}
	wait(NULL);
	output_to_pipe(bonus_data);
	execute_cmd(argv[argc - 2], envp);
	free_pipexbn_struct(bonus_data);
	return (0);
	(void)envp;
}

//TESTING PURPOSES
//./pipex_bonus here_doc limiter cmd1 cmd2 output.txt
//./pipex_bonus input.txt cmd1 cmd2 output.txt