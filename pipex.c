/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/18 07:25:18 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != 0 && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
	{
		free(s1);
		return (0);
	}
	while (s1 != 0 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 != 0 && s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char) s2[i]);
	return ((unsigned char)s1[i - 1] - (unsigned char) s2[i - 1]);
}



void	child_process2(t_var *var, char **env, int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(var->fd_close, STDOUT_FILENO);
	close(var->fd_close);
	if (execve(var->cmd2[0], var->cmd2, env) == -1)
	{
		perror("execve error2");
		exit(1);
	}
}

void	child_process(t_var *var, char **env, int pipe_fd[2])
{
	env = 0;
	close(pipe_fd[0]);
	dup2(var->fd_open, STDIN_FILENO);
	close(var->fd_open);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(var->cmd1[0], var->cmd1, env) == -1)
	{
		perror("execve error1");
		exit(1);
	}
}

char	*ft_strdup(char *s1)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(ft_strlen(s1) + 1);
	if (!arr)
		perror("strdup malloc error");
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*return_path(char **env)
{
	char *arr;
	int i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			arr = strdup(env[i] + 5);
			return (arr);
		}
		i++;
	}
	perror("path error");
	exit(1);
}



void get_path(t_var *var, char **env)
{
	char *arr;
	int	i;

	i = 0;
	arr = return_path(env);
	var->env = ft_split(arr, ':');
	while (var->env[i])
	{
		var->env[i] = ft_strjoin(var->env[i], "/");
		i++;
	}
	free(arr);
}

void	get_cmd(t_var *var, char **av)
{
	var->cmd1 = ft_split(av[2], ' ');
	var->cmd2 = ft_split(av[3], ' ');
}

void	check_cmd1(t_var *var, char *cmd)
{
	int	i;
	char *arr;

	i = 0;
	while (var->env[i])
	{
		arr = ft_strdup(var->env[i]);
		arr = ft_strjoin(arr, cmd);
		if (access(arr, F_OK) == 0)
		{
			free(var->cmd1[0]);
			var->cmd1[0] = arr;
			return ;
		}
		free(arr);
		i++;
	}
	perror("cmd error");
	exit(1);
}

void	check_cmd2(t_var *var, char *cmd)
{
	int	i;
	char *arr;

	i = 0;
	while (var->env[i])
	{
		arr = ft_strdup(var->env[i]);
		arr = ft_strjoin(arr, cmd);
		if (access(arr, F_OK) == 0)
		{
			free(var->cmd2[0]);
			var->cmd2[0] = arr;
			return ;
		}
		free(arr);
		i++;
	}
	perror("cmd error");
	exit(1);
}

void free_env(t_var *var)
{
	int i;

	i = 0;
	while (var->env[i])
	{
		free(var->env[i]);
		i++;
	}
	free(var->env);
}

void free_cmd(t_var *var)
{
	int i;

	i = 0;
	while (var->cmd1[i])
	{
		free(var->cmd1[i]);
		i++;
	}
	free(var->cmd1);
	i = 0;
	while (var->cmd2[i])
	{
		free(var->cmd2[i]);
		i++;
	}
	free(var->cmd2);
}

void	open_files(t_var *var, char **av)
{
	var->fd_open = open(av[1], O_RDONLY);
	if (var->fd_open == -1)
	{
		perror("file1 error");
		exit(1);
	}
	var->fd_close = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (var->fd_close == -1)
	{
		perror("file2 error");
		exit(1);
	}
}

void init_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1) 
	{
		perror("pipe error");
		exit(1);
	}
}

void	ft_free(t_var *var)
{
	free_env(var);
	free_cmd(var);
}

void	wait_childs(int pid1, int pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	check_cmds(t_var *var)
{
	check_cmd1(var, var->cmd1[0]);
	check_cmd2(var, var->cmd2[0]);
}

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
