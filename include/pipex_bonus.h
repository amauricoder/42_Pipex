/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:03:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/09 11:01:40 by aconceic         ###   ########.fr       */
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
	int	processes;
	int	is_heredoc;
	int	infile;
	int	outfile;
}	t_data;

/************************************/
/*            BONUS MAIN            */
/*        bonus/bonus_main.c        */
/************************************/
//
int			main(int argc, char **argv, char **envp);

/************************************/
/*               UTILS              */
/*        bonus/utils_bonus.c       */
/************************************/
//
t_data		*init_bonus_struct(int argc, char **argv);
int			arg_isvalid_bonus(int argc, char **argv);
void		error_message(char *message);

/************************************/
/*          infile/outfile files    */
/*   bonus/infile_outfile_bonus.c   */
/************************************/
//
int			here_doc(char **argv);
void		open_infile_and_redirect(char **argv, t_data *bonus_data);
void		open_outfile(t_data *bonus_data, int argc, char **argv);

/************************************/
/*             PROCESSES            */
/*  bonus/process_handling_bonus.c  */
/************************************/
//
void		process_rdrct_and_exec(t_data *d, int i, char **argv, char **envp);
void		execute_cmd_bonus(t_data *bonus_data, char *cmd_str, char **envp);

#endif