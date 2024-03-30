/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:06:22 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/30 19:36:04 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
* @brief Compare 2 strings
* @param str first string.
* @param str_tocompare second string".
* @return the value of str[i] - str_tocompare[i]
*/
int	ft_strcmp(char *str, char *str_tocompare)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' && str_tocompare[i] != '\0')
		&& str[i] == str_tocompare[i])
		i ++;
	return (str[i] - str_tocompare[i]);
}
