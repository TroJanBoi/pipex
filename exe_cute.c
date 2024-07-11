/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:53:27 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/11 16:53:27 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cute(char **env, char *av, t_pipex *data)
{
	char	**cmd;
	char	*part;

	cmd = ft_split(av, ' ');
	if (ft_count_backsl(cmd[0]) == 1)
	{
		if (check_part(cmd[0]) == 1)
			part = ft_strdup(cmd[0]);
		else
		{
			perror(cmd[0]);
			ft_free(cmd);
			ft_close_pipe(data);
			exit(EXIT_SUCCESS);
		}
	}
	else
		part = ft_fine_part(env, cmd[0]);
	if (execve(part, cmd, env) == -1)
		perror(cmd[0]);
	ft_free(cmd);
}

char	*ft_fine_part(char **env, char *cmd)
{
	int		i;
	char	**comd;
	char	*tmp;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	comd = ft_split(env[i], ':');
	tmp = ft_joinpart(comd, cmd);
	if (tmp != NULL)
	{
		ft_free(comd);
		return (tmp);
	}
	ft_free(comd);
	perror(tmp);
	return (NULL);
}
