/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:04:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 12:02:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Open the infile or transform it into here_doc if
 * is_heredoc flag is 1. here_doc flag is defined at struct_bonus_struc()
 * @param argv
 * @param bonus_data struct with data for bonuses
*/
void	open_infile(char **argv, t_pipexbn *bonus_data)
{
	if (bonus_data->is_heredoc == 0)
		bonus_data->infile = open(argv[1], O_RDONLY);
	else
		bonus_data->infile = here_doc(argv);
	if (bonus_data->infile == -1)
	{
		perror("open_infile ");
		exit(EXIT_FAILURE);
	}
	dup2(bonus_data->infile, STDIN_FILENO);
}

/**
 * @brief Function to get the input from fd 0 and write 
 * it to a temp file called here_doc.
 * @attention get_next_line modified to prevent leaks
 * @param argv arguments -> used to find the limiter and stop get_next_line
 * @return fd opened for the temp file.
*/
int	here_doc(char **argv)
{
	int		infile;
	char	*line;

	infile = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (infile == -1)
	{
		perror("Here_doc ");
		unlink("here_doc");
		return (0);
	}
	ft_printf("Infile before(here_doc()) -> %i\n", infile);
	while (1)
	{
		write(1, "heredoc>", 8);
		line = get_next_line(0);
		if (line == NULL)
			return (-1);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& (ft_strlen(line) - 1) == ft_strlen(argv[2]))
			break ;
		write(infile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(infile);
	infile = open("here_doc", O_RDONLY);
	if (infile == -1)
	{
		perror("Here_doc ");
		unlink("here_doc");
		return (0);
	}
	ft_printf("Infile after(here_doc()) -> %i\n", infile);
	return (infile);
}

void	open_outfile(t_pipexbn *bonus_data, int argc, char **argv)
{
	bonus_data->outfile = open(argv[argc - 1],
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (bonus_data->outfile == -1)
	{
		perror("open_outfile ");
	}
}
