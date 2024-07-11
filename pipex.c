/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:33:28 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/11 16:56:05 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_children(char **env, t_pipex *data, char **av)
{
	data->fdin = open(av[1], O_RDONLY);
	if (data->fdin < 0)
	{
		close(data->fdin);
		ft_close_pipe(data);
		exit(EXIT_FAILURE);
	}
	dup2(data->fdin, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	close(data->fdin);
	exe_cute(env, av[2], data);
}

void	ft_parents(char **env, t_pipex *data, char **av)
{
	data->fdout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fdout < 0)
		exit(EXIT_FAILURE);
	dup2(data->fd[0], 0);
	dup2(data->fdout, 1);
	close(data->fd[1]);
	close(data->fdout);
	exe_cute(env, av[3], data);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipex	data;

	if (ac != 5)
		ft_error("Error 505", 2);
	if (!check_file(av[1]))
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	if (pipe(data.fd) == -1)
		ft_error("Error pip", 2);
	data.pid_ch = fork();
	if (data.pid_ch == 0)
		ft_children(envp, &data, av);
	data.pid_pr = fork();
	if (data.pid_pr == 0)
		ft_parents(envp, &data, av);
	ft_close_pipe(&data);
	waitpid(data.pid_ch, NULL, 0);
	waitpid(data.pid_pr, NULL, 0);
}
