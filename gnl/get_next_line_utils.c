/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:30:29 by xx                #+#    #+#             */
/*   Updated: 2025/06/17 14:24:51 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[len] = '\0';
	free(s1);
	return (res);
}
int	ft_strcpy(char *dest, char *src, int i)
{
	int	j;

	j = 0;
	if (!src)
		return (i);
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	return (i + j);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	size_t			total_size;
	unsigned char	*a;

	total_size = nmemb * size;
	p = malloc(total_size);
	if (!p)
		return (NULL);
	a = (unsigned char *)p;
	while (total_size--)
	{
		*a++ = 0;
	}
	return (p);
}
