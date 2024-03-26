/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/26 13:37:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//Compare 2 strgs
//0 for equals.
int	ft_strcmp(char *str, char *str_tocompare)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' && str_tocompare[i] != '\0')
		&& str[i] == str_tocompare[i])
		i ++;
	return (str[i] - str_tocompare[i]);
}
