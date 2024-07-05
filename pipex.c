/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:33:28 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/06 00:59:15 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(char *filename)
{
	if (access(filename, R_OK) == 0)
		return ;
	else if (access(filename, R_OK | W_OK) == 0)
		return ;
	else
		perror(filename);
}

void	ft_fine_path(char **env, char *av)
{
	
}

void	exe_cute(char **env,  char *av)
{
	// dprintf(2, "open exe_cute\n");
	// char *argv[] = { av, NULL, NULL };
	char	**cmd;

	cmd = ft_split(av, ' ');
	ft_fine_path(env, cmd[0]);
	dprintf(2, "cmd : %s\n", cmd[0]);
	// while (env[i] != NULL)
	// {
	// 	dprintf(2, "[%d]-env - %s\n", i, env[i]);
	// 	if ()
	// 	i++;
	// }
	// dprintf(2, "av : %s\n", av);
	// execve(av, argv, env);
}

void	ft_children(char **env, t_pipex *data, char **av)
{
	data->fdin = open(av[1], O_RDONLY);
	check_file(av[1]);
	if (data->fdin < 0)
		exit(EXIT_FAILURE);
	dup2(data->fdin, 0);
	dup2(data->fd[1], 1);
	close(data->fd[0]);
	exe_cute(env, av[2]);
}

void	ft_parents(char **env, t_pipex *data, char **av)
{
	// if (data->fdin == 2)
	// 	exit(EXIT_FAILURE);
	dprintf(2, "open->\n");
	data->fdout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	check_file(av[4]);
	dup2(data->fd[0], 0);
	dup2(data->fdout, 1);
	close(data->fd[1]);
	exe_cute(env, av[3]);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipex	data;
	pid_t	pid;

	if (ac != 5)
		ft_error("Error 505", 2);
	if (pipe(data.fd) == -1)
		ft_error("Error pip", 2);
	// printf("fd->0 : %d\n", data.fd[0]);
	// printf("fd->1 : %d\n", data.fd[1]);
	pid = fork();
	if (pid == -1)
		ft_error("Error pid", 2);
	// printf("pid : %d\n", pid);
	if (pid == 0)
		ft_children(envp, &data, av);
	// printf("success children\n");
	waitpid(pid, NULL, 0);
	ft_parents(envp, &data, av);
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