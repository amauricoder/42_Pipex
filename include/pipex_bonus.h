/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:03:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/08 21:15:32 by aconceic         ###   ########.fr       */
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
}	t_pipexbn;

/************************************/
/*               UTILS              */
/*        bonus/utils_bonus.c       */
/************************************/
//
t_pipexbn	*init_bonus_struct(int argc, char **argv);
int			arg_isvalid_bonus(int argc, char **argv);
void		error_message(char *message);

/************************************/
/*          infile/outfile files    */
/*   bonus/infile_outfile_bonus.c   */
/************************************/
//
int			here_doc(char **argv);
void		open_infile_and_redirect(char **argv, t_pipexbn *bonus_data);
void		open_outfile(t_pipexbn *bonus_data, int argc, char **argv);

/************************************/
/*             PROCESSES            */
/*  bonus/process_handling_bonus.c  */
/************************************/
//
void    process_redirect_and_exec(t_pipexbn *d, int i, char **argv, char **envp);

#endif