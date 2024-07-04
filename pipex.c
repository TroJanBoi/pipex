/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:33:28 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/05 01:54:27 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkfd(t_pipex *data)
{
	printf("fd : %d\n", data->fd1);
	if (data->fd1 == -1)
		perror(data->fname);
}

int		ft_openfile(t_pipex *data)
{
	// char	*buffer;
	// char	*tmp;

	data->fd1 = open(data->fname, O_RDONLY);
	ft_checkfd(data);
	// buffer = ft_strdup(" ");
	return (0);
}

void	ft_init(t_pipex	*data, char **av)
{
	data->fname = ft_strdup(av[1]);
	data->fd1 = ft_openfile(data);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipex		data;
	// if (ac != 5)
	// 	ft_error("Error", 2);
	// ft_init(&data, av);
	// char * const argv[] = {"/usr/bin/grep", "a", NULL};
	// printf("exe %d\n", execve(data.fname, argv, NULL));
	char	*greps[] = {"grep", "a1", NULL};
	data.fd1 = open(av[1], O_RDONLY);
	data.fd2 = open(av[2], O_WRONLY);

	printf("dup2 : %d\n", dup2(data.fd1, 0));
	close (data.fd1);
	close (data.fd2);

	printf("execve %d\n", execve("grep", greps, envp));
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