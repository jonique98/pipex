/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/19 01:55:40 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_var	var;
	int		pipe_fd[2];
	int		pid1;
	int		pid2;

	if (ac != 5)
		perror("인자가 5개가 아닙니다.");
	open_files(&var, av);
	get_path(&var, env);
	get_cmd(&var, av);
	check_cmds(&var);
	init_pipe(pipe_fd);
	pid1 = fork();
	if (pid1 == 0)
		child_process(&var, env, pipe_fd);
	else
		close(pipe_fd[1]);
	pid2 = fork();
	if (pid2 == 0)
		child_process2(&var, env, pipe_fd);
	else
		close(pipe_fd[0]);
	wait_childs(pid1, pid2);
	ft_free(&var);
}
