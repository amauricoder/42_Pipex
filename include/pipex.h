/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:03 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/06 15:37:08 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/************************************/
/*         GENERAL INCLUDES         */
/************************************/
# include <stdio.h> //printf()
# include <stdlib.h> //mallocs(), free(), exit()
# include <fcntl.h> //open()
# include <string.h> //strerror()
# include <unistd.h> //dup(), dup2(), fork()
# include <sys/wait.h> //wait()
# include <errno.h> //perror()

/************************************/
/*         External Libraries       */
/************************************/
# include "../libraries/libft/libft.h"

/************************************/
/*              Struct              */
/************************************/
typedef struct s_pstruct
{
    int pid;
    int pid2;
    int pipefd[2];
}   t_pstruct;

/************************************/
/*               MAIN               */
/*          source/main.c           */
/************************************/
int	main(int argc, char **argv);

/************************************/
/*            FT_ERROR              */
/*      source/ft_error.c           */
/************************************/

#endif