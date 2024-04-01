/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:49:55 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/01 19:48:32 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/**
 * @brief Initialize and allocate memory for struct of pipex bonus
 * @attention Allocate memory.
 * @param argc
 * @param argv
 * @return The struct with values initialized
*/
t_pipexbn	*init_bonus_struct(int argc, char **argv)
{
    t_pipexbn *bonus_data;

    bonus_data = ft_calloc(sizeof(t_pipexbn), 1);
    if (!bonus_data)
        return (NULL);
    bonus_data->processes = argc - 3;
    if (!ft_strcmp(argv[1], "here_doc"))
		bonus_data->processes --;

    return (bonus_data);
}
