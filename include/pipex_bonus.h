/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:03:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/01 19:40:56 by aconceic         ###   ########.fr       */
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
    int pid;
    int processes;
    int **pipesfd;

}   t_pipexbn;

/************************************/
/*       error_handling_bonus.c     */
/*    bonus/error_handling_bonus.c  */
/************************************/
//
int	arg_isvalid_bonus(int argc, char **argv);
/************************************/
/*           utils_bonus.c          */
/*        bonus/utils_bonus.c       */
/************************************/
//
t_pipexbn   *init_bonus_struct(int argc, char **argv);
/************************************/
/*           utils_bonus.c          */
/*        bonus/utils_bonus.c       */
/************************************/
//
int	**alloc_pipes(t_pipexbn *bonus_data);

#endif