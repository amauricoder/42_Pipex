/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:34:03 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/03 10:43:58 by aconceic         ###   ########.fr       */
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
	int	pid;
	int	pipefd[2];
}	t_pstruct;

/************************************/
/*               MAIN               */
/*          source/main.c           */
/************************************/
int		main(int argc, char **argv, char **envp);

/************************************/
/*            FT_UTILS              */
/*        source/ft_utils.c         */
/************************************/
int		ft_strcmp(char *str, char *str_tocompare);

/************************************/
/*            CMD_TREATMENT        */
/*        source/cmd_treatment.c    */
/************************************/
char	**cmd_handling(char *cmd_complete);

/************************************/
/*          PIPEX_REDIRECT          */
/*       source/pipex_redirect.c    */
/************************************/
void	redirect_parentfd(char **argv, t_pstruct pipex);
void	redirect_childfd(char **argv, t_pstruct pipex);

/************************************/
/*           PIPEX_EXECUTE          */
/*        source/pipex_execute.c    */
/************************************/
void	execute_cmd(char *cmd_str, char **envp);
char	*find_execpath(char **envp);

/************************************/
/*          ERROR_HANDLING          */
/*       source/error_handling.c    */
/************************************/
void	error_management(char *msg);
void	free_execute_cmd(char **cmd_arg, char **pp);
char	*create_cmdpath(char *possible_path, char *command);
int		arg_isvalid(int argc, char **argv);

#endif