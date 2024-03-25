/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:12:04 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/25 14:51:49 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_management(int error)
{
	//dont forget to make frees()
	if (error == 1)
	{
		write(2, "Error\nIncorrect Arguments\n", 27);
		exit(EXIT_FAILURE);
	}
	else if (error == 2)
	{
		perror("Fork() :");
		exit(EXIT_FAILURE);
	}
	else if (error == 3)
	{
		perror("execve cmd");
		exit(EXIT_FAILURE);
	}
	else if (error == 4)
	{
		perror("execve cmd child");
		exit(EXIT_FAILURE);
	}
}
