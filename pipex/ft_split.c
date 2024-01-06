/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:27:43 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/18 07:44:12 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_inside(char const *s, char c)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(ft_word_len(s, c) + 1);
	if (!arr)
		return (0);
	while (s[i] && s[i] != c)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int	ft_word_num(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

void	make_arr(char const *s, char c, char **arr)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			*(arr + i) = ft_inside(s, c);
			if (*(arr + i) == 0)
			{
				perror("split error(memory error)");
				exit(1);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	*(arr + i) = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (ft_word_num(s, c) + 1));
	if (!arr)
		return (0);
	make_arr(s, c, arr);
	return (arr);
}
