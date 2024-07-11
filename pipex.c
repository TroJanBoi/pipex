/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:33:28 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/11 00:24:38 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(t_pipex *data, char *filename)
{
	data->fdin = open(filename, O_RDONLY);
	if (data->fdin < 0)
		return (0);
	else
	{
		if (access(filename, R_OK) == 0)
			return (1);
		else if (access(filename, R_OK | W_OK) == 0)
			return (1);
		else
			return (0);
	}
	return (1);
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

char	*ft_fine_part(char **env, char *cmd)
{
	int		i;
	char	**comd;
	char	*ucmd;
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
	return (NULL);
}

void	exe_cute(char **env,  char *av, t_pipex *data)
{
	char	**cmd;
	char	*part;

	cmd = ft_split(av, ' ');
	part = ft_fine_part(env, cmd[0]);
	if (execve(part, cmd, env) == -1)
		perror(part);
	ft_free(cmd);
}

void	ft_children(char **env, t_pipex *data, char **av)
{
	data->fdin = open(av[1], O_RDONLY);
	if (data->fdin < 0)
		exit(EXIT_FAILURE);
	dup2(data->fdin, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	exe_cute(env, av[2], data);
}

void	ft_parents(char **env, t_pipex *data, char **av)
{
	data->fdout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	check_file(data, av[4]);
	dup2(data->fd[0], 0);
	dup2(data->fdout, 1);
	close(data->fd[1]);
	exe_cute(env, av[3], data);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipex	data;

	if (ac != 5)
		ft_error("Error 505", 2);
	if (!check_file(&data, av[1]))
	{
		close(data.fdin);
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
	if (pipe(data.fd) == -1)
		ft_error("Error pip", 2);
	data.pid_ch = fork();
	if (data.pid_ch == -1)
		dprintf(2, "Error data.pid_ch\n");
	if (data.pid_ch == 0)
		ft_children(envp, &data, av);
	data.pid_pr = fork();
	if (data.pid_pr == -1)
		dprintf(2, "Error data.pid_pr\n");
	if (data.pid_pr == 0)
		ft_parents(envp, &data, av);
	close(data.fd[0]);
	close(data.fd[1]);
	waitpid(data.pid_ch, NULL, 0);
	printf("finish\n");
}

// if (ac != 2)
// {
// 	fprintf(stderr, "use : <filename>");
// 	return (EXIT_FAILURE);
// }

// if (!access(av[1], R_OK|W_OK))
// {
// 	printf("ok read and write %s\n", av[1]);
// 	return (EXIT_SUCCESS);
// }
// else
// {
// 	perror(av[1]);
// 	return (EXIT_FAILURE);
// }

// t_pipex		data;
// if (ac != 5)
// 	ft_error("Error", 2);
// ft_init(&data, av);
// char * const argv[] = {"/usr/bin/grep", "a", NULL};
// printf("exe %d\n", execve(data.fname, argv, NULL));
// char	*greps[] = {"grep", "a1", NULL};
// data.fd1 = open(av[1], O_RDONLY);
// data.fd2 = open(av[2], O_WRONLY);

// printf("dup2 : %d\n", dup2(data.fd1, 0));
// close (data.fd1);
// close (data.fd2);

// printf("execve %d\n", execve("grep", greps, envp));
// int	i = 0;
// while (envp[i])
// 	printf("%s\n", envp[i++]);