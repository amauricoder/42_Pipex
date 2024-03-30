/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:50:05 by aconceic          #+#    #+#             */
/*   Updated: 2024/03/30 18:37:32 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
char	**cmd_handling(char **argv)
{
	char	**cmd_handled;
	char	*cmd_cleaned;
	//int	i = 0;

	cmd_cleaned = cmd_join(argv);
	cmd_handled = ft_split(cmd_cleaned, '\n');
	free(cmd_cleaned);
	return (cmd_handled);
}
char	*cmd_join(char **argv)
{
	char	*cmd_totreat;
	char	*cmd_treated;
	char	*temp;
	char	*temp2;
	int i;

	cmd_totreat = ft_strdup(" ");
	i = 0;
	while (argv[i])
	{
		temp = ft_strjoin(argv[i], "\n");
		temp2 = ft_strjoin(cmd_totreat, temp);
		free(cmd_totreat);
		free(temp);
		cmd_totreat = temp2;
		i ++;
	}
	cmd_treated = clean_cmd(cmd_totreat);
	free(temp2);
	return (cmd_treated);
}

char	*clean_cmd(char *cmd_toclean)
{
	int i;
	int	j;
	int	qt;
	char	*cmd_cleaned;

	i = -1;
	qt = 0;
	while (cmd_toclean[++i])
		if (cmd_toclean[i] == 39 || cmd_toclean[i] == 34)
			qt ++;
	cmd_cleaned = ft_calloc(sizeof(char), ft_strlen(cmd_toclean) - qt + 1);
	if (!cmd_cleaned)
		return (NULL);
	i = -1;
	j = -1;
	while (cmd_toclean[++i])
	{
		if (cmd_toclean[i] == 39 || cmd_toclean[i] == 34)
			i ++;
		cmd_cleaned[++j] = cmd_toclean[i];
	}
	
	return (cmd_cleaned);
}
