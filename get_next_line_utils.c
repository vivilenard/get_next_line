/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:35:51 by vlenard           #+#    #+#             */
/*   Updated: 2022/12/01 12:13:45 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	n;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (ft_strlen(s1) > 0 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n] != '\0')
	{
		str[i] = s2[n];
		i++;
		n++;
	}
	str[len - 1] = '\0';
	return (free ((char *)s1), free ((char *)s2), str);
}


char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = (unsigned char) c;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *)s + i);
		i++;
	}
	if (uc == s[i])
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	len;
	char	*scpy;

	i = 0;
	len = ft_strlen(s);
	scpy = (char *)malloc((len + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	while (i < len)
	{
		*(scpy + i) = *(s + i);
		i++;
	}
	if (i == len)
		*(scpy + i) = *(s + i);
	return (scpy);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
