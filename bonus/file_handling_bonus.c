/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:04:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/03 14:39:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/* void	open_input(char **argv, t_pipexbn *bonus_data)
{
	int	infile;

	if (bonus_data->is_heredoc == 0)
		infile = open(argv[1], O_RDONLY);
	else
	//	infile = here_doc()
} */

int	here_doc(char **argv)
{
	int	infile;
	char *line;

	infile = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	if (infile == -1)
	{
		write(2, "Erro linha 32 open bonitao\n", 28);
		return (0);
	}
	ft_printf("Limiter => %s\n", argv[2]);
	while (1)
	{
		write(1, "here_doc>", 10);
		line = get_next_line(0);
		if (line == NULL)
			return (-1);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
			break;
		write(infile, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(infile);
	return (infile);
}
