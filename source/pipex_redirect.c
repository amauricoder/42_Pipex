/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:02:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/30 19:38:47 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
/**
* @brief Redirect stdin to read from the read end of the pipe (pipefd[0])
* @brief Redirect stdout to write to the output file.
* @param argv inputs (arguments vector)
* @param pipex struct that stores values for pipefd
*/
void	redirect_parentfd(char **argv, t_pstruct pipex)
{
	int	output_fd;

	output_fd = open(argv[4], O_CREAT | O_WRONLY, 0644);
	if (output_fd < 0)
		error_management("Error\nParent Output_fd");
	close(pipex.pipefd[1]);
	if (dup2(pipex.pipefd[0], STDIN_FILENO) == -1
		|| dup2(output_fd, STDOUT_FILENO) == -1)
		error_management("Error\nParent Dup2()");
	close(output_fd);
	close(pipex.pipefd[0]);
}

/**
* @brief Redirect stdout to write to the write end of the pipe (pipefd[1])
* @brief Redirect stdin to read from the input file.
* @param argv inputs (arguments vector)
* @param pipex struct that stores values for pipefd
*/
void	redirect_childfd(char **argv, t_pstruct pipex)
{
	int	input_fd;

	input_fd = open(argv[1], O_RDONLY, 0644);
	if (input_fd < 0)
		error_management("Error\nChild Input_fd");
	close(pipex.pipefd[0]);
	if (dup2(input_fd, STDIN_FILENO) == -1
		|| dup2(pipex.pipefd[1], STDOUT_FILENO) == -1)
		error_management("Error\nChild Dup2()");
	close(input_fd);
	close(pipex.pipefd[1]);
}
