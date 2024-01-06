/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:38:18 by sumjo             #+#    #+#             */
/*   Updated: 2023/12/30 02:25:57 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*return_path(char **env)
{
	char	*arr;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			arr = ft_strdup(env[i] + 5);
			return (arr);
		}
		i++;
	}
	perror("path error");
	exit(1);
}

void	get_path(t_var *var, char **env)
{
	char	*arr;
	int		i;

	i = 0;
	arr = return_path(env);
	var->path = ft_split(arr, ':');
	while (var->path[i])
	{
		var->path[i] = ft_strjoin(var->path[i], "/");
		i++;
	}
	free(arr);
}
