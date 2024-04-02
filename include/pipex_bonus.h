/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:03:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/02 15:59:21 by aconceic         ###   ########.fr       */
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
}   t_pipexbn;

/************************************/
/*       error_handling_bonus.c     */
/*    bonus/error_handling_bonus.c  */
/************************************/
//
int			arg_isvalid_bonus(int argc, char **argv);
/************************************/
/*           utils_bonus.c          */
/*        bonus/utils_bonus.c       */
/************************************/
//
t_pipexbn	*init_bonus_struct(int argc, char **argv);
int			**alloc_pipefds(int processes_qt);
int			*alloc_pids(int processes_qt);

/************************************/
/*           utils_bonus.c          */
/*        bonus/utils_bonus.c       */
/************************************/
//

#endif