/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:35:47 by vlenard           #+#    #+#             */
/*   Updated: 2022/11/30 16:25:17 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_readtostat(int fd, char *stat)
{
	int flag;
	char *buf;
	
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	printf("hi\n");
	buf[BUFFER_SIZE] = '\0';
	flag = read(fd, buf, BUFFER_SIZE);
	printf("hi\n");
	printf("hii\n");
	stat = ft_strjoin(stat, buf);
	free (buf);
	return (stat);
}
/*char *ft_stattoline(char *stat, char *line)
{
	
	return (line);
}
*/
char *get_next_line(int fd)
{
	static char *stat;
	char *line;

	printf("hi\n");
	line = malloc(1);
	line[0] = '\0';
	if (stat)
	{
		printf("hi\n");
		line = ft_strjoin(stat, line);
		free (stat);
	}
	printf("hi\n");
	stat = ft_readtostat(fd, stat);
	//line = ft_stattoline(stat, line);
	printf("hiiiii\n");
	return (stat);
}