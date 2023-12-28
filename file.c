/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:41:08 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/19 04:55:41 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_var *var, char **av)
{
	var->fd_open = open(av[1], O_RDONLY);
	if (var->fd_open == -1)
		perror_exit("file1 error");
	var->fd_close = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (var->fd_close == -1)
		perror_exit("file2 error");
}

void	init_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		perror_exit("pipe error");
}
