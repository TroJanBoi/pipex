/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesrisaw <pesrisaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 00:50:53 by pesrisaw          #+#    #+#             */
/*   Updated: 2024/07/11 17:06:16 by pesrisaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipex
{
	int		fdin;
	int		fdout;
	int		fd[2];
	char	*fname;
	int		status;
	pid_t	pid_ch;
	pid_t	pid_pr;
}	t_pipex;

void	ft_error(char *str, int fd);
void	ft_free(char **av);
void	ft_close_pipe(t_pipex *data);
void	exe_cute(char **env, char *av, t_pipex *data);
char	*ft_fine_part(char **env, char *cmd);
int		check_file(char *filename);
int		check_part(char *cmd);
char	*ft_joinpart(char **comd, char *cmd);
int		ft_count_backsl(char *str);
#endif