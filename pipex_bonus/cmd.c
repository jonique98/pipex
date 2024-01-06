/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:40:16 by sumjo             #+#    #+#             */
/*   Updated: 2023/12/30 05:06:15 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_commands(t_var *var, char **cmd)
{
	int		i;
	char	*arr;

	i = 0;
	while (var->path[i])
	{
		arr = ft_strdup(var->path[i]);
		arr = ft_strjoin(arr, cmd[0]);
		if (access(arr, F_OK) == 0)
		{
			cmd[0] = arr;
			return ;
		}
		free(arr);
		i++;
	}
	perror_exit("cmd error", 1);
}

char	**return_commands(t_var *var, char *av)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (cmd[0][0] != '/')
	{
		parse_commands(var, cmd);
		return (cmd);
	}
	return (cmd);
}

void	is_valid_command(t_var *var, char **cmd)
{
	int		is_valid;
	int		i;
	char	*arr;

	i = -1;
	is_valid = 0;
	while (var->path[++i])
	{
		arr = ft_strdup(var->path[i]);
		arr = ft_strjoin(arr, cmd[0]);
		if (access(arr, F_OK) == 0)
		{
			is_valid = 1;
			free(arr);
			break ;
		}
		free(arr);
	}
	if (is_valid == 0)
		perror_exit("cmd error", 1);
}

void	check_commands(t_var *var, int ac, char **av)
{
	int		i;
	char	**cmd;

	i = 1;
	while (++i < ac - 1)
	{
		cmd = ft_split(av[i], ' ');
		if (ft_strncmp(cmd[0], "here_doc", 8) == 0
			&& cmd[1] == NULL)
			continue ;
		is_valid_command(var, cmd);
	}
	var->cmd_num = ac - 3;
}
