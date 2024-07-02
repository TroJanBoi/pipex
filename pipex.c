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

int	main(int ac, char **av)
{
	if (ac != 5)
		ft_error("Error", 2);
	
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