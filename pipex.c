/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:33:28 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/02 23:06:38 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkfd(int	fd)
{
	if (fd < 0)
		printf("bash: %s: No such file Dicrectory\n", s);
}

int		ft_openfile(t_pipex *data)
{
	data->fd1 = open(data->fname, O_RDONLY);
	ft_checkfd(data->fd1);
}

void	ft_init(t_pipex	*data, char **av)
{
	data->fname = ft_strdup(av[1]);
	data->fd1 = ft_openfile(data);
}

int	main(int ac, char **av)
{
	t_pipex		data;

	if (ac != 5)
		ft_error("Error", 2);
	ft_init(&data, av);
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