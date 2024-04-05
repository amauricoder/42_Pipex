/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:03:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/05 15:30:38 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/************************************/
/*            Main Header           */
/************************************/
# include "pipex.h"

/************************************/
/*           Bonus features         */
/************************************/

typedef struct s_pipexbn
{
	int processes;
	int is_heredoc;
	int **pipesfd_arr;
	int *pid_arr;
	int	infile;
	int outfile;
}   t_pipexbn;

/************************************/
/*               INPUT              */
/*    bonus/input_handling_bonus.c  */
/************************************/
//
int			arg_isvalid_bonus(int argc, char **argv);

/************************************/
/*               UTILS              */
/*        bonus/utils_bonus.c       */
/************************************/
//
t_pipexbn	*init_bonus_struct(int argc, char **argv);
int			**alloc_pipefds(int processes_qt);
int			*alloc_pids(int processes_qt);

/************************************/
/*               PIPES              */
/*   bonus/pipes_handling_bonus.c   */
/************************************/
//
void	create_pipes(t_pipexbn *bonus_data);
int		fork_arr(t_pipexbn *bonus_data, int i);
void	input_to_pipe(t_pipexbn *bonus_data);
void	output_to_pipe(t_pipexbn *bonus_data);

/************************************/
/*          infile/outfile files    */
/*    bonus/file_handling_bonus.c   */
/************************************/
//
int		here_doc(char **argv);
void	open_infile(char **argv, t_pipexbn *bonus_data);
void	open_outfile(t_pipexbn *bonus_data, int argc, char **argv);

/************************************/
/*               ERRORS             */
/*    bonus/error_handling_bonus.c  */
/************************************/
//
void    free_pipexbn_struct(t_pipexbn *bonus_data);
void	error_message(char *message);
/************************************/
/*             PROCESSES            */
/*  bonus/process_handling_bonus.c  */
/************************************/
//
int		child_process(t_pipexbn *bonus_data, int i, char **argv, char **envp);
int 	parent_process(t_pipexbn *bonus_data, char **argv, char **envp);

/************************************/
/*             DEBUG                */
/*     bonus/debugging_session.c    */
/************************************/
//
int qt_pipes(t_pipexbn *bonus_data);

#endif