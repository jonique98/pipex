
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

int main()
{
	int fd[2];
	pipe(fd);
	write(fd[1], "hello", 5);
	char *str = malloc(100);
	read(fd[0], str, 100);
	printf("%s\n", str);
}
