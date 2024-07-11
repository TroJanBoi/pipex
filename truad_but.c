/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_naja.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:55:51 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/11 16:55:51 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(char *filename)
{
	if ((access(filename, R_OK) || access(filename, R_OK | W_OK)) == 0)
		return (1);
	else
		return (0);
}

int	check_part(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (1);
	return (0);
}

char	*ft_joinpart(char **comd, char *cmd)
{
	int		i;
	char	*tmp;
	char	*ucmd;

	i = 0;
	ucmd = ft_substr("", 0, 0);
	while (comd[i])
	{
		tmp = ucmd;
		ucmd = ft_strjoin(comd[i], "/");
		free(tmp);
		tmp = ucmd;
		ucmd = ft_strjoin(ucmd, cmd);
		free(tmp);
		if (check_part(ucmd) == 1)
			return (ucmd);
		i++;
	}
	return (NULL);
}

int	ft_count_backsl(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '/')
			count++;
		i++;
	}
	if (count > 0)
		return (1);
	return (0);
}
