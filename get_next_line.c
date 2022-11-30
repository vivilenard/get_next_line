/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karllenard <karllenard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:35:47 by vlenard           #+#    #+#             */
/*   Updated: 2022/11/30 20:52:20 by karllenard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_readtostat(int fd, char *stat)
{
	int flag;
	char *buf;

	flag = 9;
	while (flag != 0 && flag != -1 && ft_strchr(stat, '\n') == 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		ft_bzero(buf, BUFFER_SIZE + 1);
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag == -1 || flag == 0)
		{
			printf("stati %s\n", stat);
			return (free(buf), stat);
		}
			printf("buf %s\n", buf);
		stat = ft_strjoin(stat, buf);
		free (buf);
	}
	printf("flag %d\n", flag);
	return (stat);
}
char *ft_stattoline(char *stat, char **line)
{
	char *buf;
	int	i;
	i = 0;

	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	printf("%d\n", i);
	*line = malloc(i + 1);
	if (!*line)
		return (NULL);
	i = 0;
	while (stat[i] != '\n' && stat[i] != '\0')
	{
		*(*line + i) = stat[i];
		i++;
	}
		printf("%d\n", i);
		printf("trueline %s\n", *line);
	if (stat[i] == '\n')
		*(*line + i) = '\0';
	if (stat[i] == '\0')
		return (NULL);
	buf = ft_strdup(stat + i + 1);
	return (buf);
}

char *get_next_line(int fd)
{
	static char *stat;
	char *line;
	
	line = NULL;
	printf("stat1 %s\n", stat);
	stat = ft_readtostat(fd, stat);
	printf("stat1.5 %s\n", stat);
	if (stat == NULL)
		return (NULL);
		printf("stat2 %s\n", stat);
	stat = ft_stattoline(stat, &line);
		printf("stat3 %s\n", stat);
		printf("line %s\n", line);
	return (line);
}

