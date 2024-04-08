/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 22:01:56 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Validade arguments, Init struct with data, check here_doc
 * open infile and redirect to STDIN_FILENO, open outfile,
 * redirect processes input and output through pipe and execute command.
 */
int	main(int argc, char **argv, char **envp)
{
	t_pipexbn	*bonus_data;
	int			i;

	if (!arg_isvalid_bonus(argc, argv) || !envp || envp[0][0] == '\0')
		error_message("Error\nInvalid arguments or empty envp");
	bonus_data = init_bonus_struct(argc, argv);
	open_infile_and_redirect(argv, bonus_data);
	open_outfile(bonus_data, argc, argv);
	i = 0;
	while (i < bonus_data->processes - 1)
		process_redirect_and_exec(bonus_data, i ++, argv, envp);
	if (bonus_data->is_heredoc == 1)
		unlink("here_doc.temp");
	dup2(bonus_data->outfile, STDOUT_FILENO);
	execute_cmd(argv[argc - 2], envp);
	return (0);
}
//./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
//< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

// ./pipex here_doc LIMITER cmd0 cmd1 file
// cmd << LIMITER | cmd1 >> file
