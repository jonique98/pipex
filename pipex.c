/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/16 08:41:13 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strlen(char *str)
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
	// free(s1);
	return (arr);
}

// int child_process2(char **av, t_fd fd, int *pipe_fd, char **env)
// {
// 	dup2(pipe_fd[0], STDIN_FILENO);
// 	close(pipe_fd[0]);
// 	av++;
// 	av[0] = ft_strjoin("/bin/", av[0]);
// 	char *arr[] = {av[0], NULL};
// 	dup2(fd.fd_close, STDOUT_FILENO);
// 	if (execve(av[0], arr, env) == -1)
// 	{
// 		perror("execve error2");
// 		return 0;
// 	}
// 	return (0);
// }

// int child_process(char **av, t_fd fd, char **env)
// {
// 	dup2(fd.fd_open, STDIN_FILENO);
// 	int pid;
// 	int pipe_fd[2];

// 	av++;
// 	av[0] = ft_strjoin("/bin/", av[0]);
// 	char *arr[] = {av[0], NULL};
// 	if (pipe(pipe_fd) == -1) 
// 	{		
// 		perror("pipe error");
// 		return 1;
// 	}
// 	dup2(pipe_fd[1], STDOUT_FILENO);
// 	close(pipe_fd[1]);
// 	if (execve(av[0], arr, env) == -1)
// 	{
// 		perror("execve error1");
// 		exit(1);
// 	}
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		child_process2(av, fd, pipe_fd, env);
// 		return 0;
// 	}
// 	else
// 		waitpid(pid, NULL, 0);
// 	return 0;
// }

// int main(int ac, char **av, char **env) 
// {
// 	ac = 0;
// 	t_fd fd;
// 	// int pipe_fd[2]; // 파이프 파일 디스크립터 배열
// 	int pid;
	
// 	av++;
// 	fd.fd_open = open(av[0], O_RDONLY, 0777);
// 	if (fd.fd_open == -1)
// 	{
// 		perror("file1 error");
// 		exit(1);
// 	}
// 	fd.fd_close = open(av[3], O_WRONLY, 0777);
// 	if (fd.fd_close == -1)
// 	{
// 		perror("file2 error");
// 		exit(1);
// 	}
// 	// if (pipe(pipe_fd) == -1) 
// 	// {
// 	// 	perror("pipe error");
// 	// 	return 1;
// 	// }
// 	char *ar;
// 	ar = malloc(11);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		child_process(av, fd, env);
// 		return 0;
// 	}
// 	else
// 		waitpid(pid, NULL, 0);
// }



void child_process2(char **av, t_fd fd, char **env, int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	av[0] = ft_strjoin("/bin/", av[0]);
	char *arr[] = {av[0], NULL};
	dup2(fd.fd_close, STDOUT_FILENO);
	close(fd.fd_close);
	if (execve(av[0], arr, env) == -1)
	{
		perror("execve error2");
		return ;
	}
	// printf("자식2 끝\n");
	// return (0);
}

void child_process(char **av, t_fd fd, char **env, int pipe_fd[2])
{
	close(pipe_fd[0]);
	av[0] = ft_strjoin("/bin/", av[0]);
	char *arr[] = {av[0], NULL};
	dup2(fd.fd_open, STDIN_FILENO);
	close(fd.fd_open);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(av[0], arr, env) == -1)
	{
		perror("execve error1");
		return ;
	}
	// return 0;
}

int main(int ac, char **av, char **env) 
{
	ac = 0;
	t_fd fd;
	int pipe_fd[2]; // 파이프 파일 디스크립터 배열
	int pid1;
	int pid2;
	
	av++;
	fd.fd_open = open(av[0], O_RDONLY, 0777);
	if (fd.fd_open == -1)
	{
		perror("file1 error");
		exit(1);
	}
	fd.fd_close = open(av[3], O_WRONLY, 0777);
	if (fd.fd_close == -1)
	{
		perror("file2 error");
		exit(1);
	}
	if (pipe(pipe_fd) == -1) 
	{
		perror("pipe error");
		return 1;
	}
	pid1 = fork();
	printf("자식1의 pid = %d\n", pid1);
	if (pid1 == 0)
	{
		av++;
		printf("자식1의 인자 = %s\n", av[0]);
		child_process(av, fd, env, pipe_fd);
	}
	av++;
	pid2 = fork();
	printf("자식2의 pid = %d\n", pid2);
	if (pid2 == 0)
	{
		av++;
		printf("자식2의 인자 = %s\n", av[0]);
		child_process2(av, fd, env, pipe_fd);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	printf("끝\n");
}
