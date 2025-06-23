/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xx <xx@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:59:17 by xx                #+#    #+#             */
/*   Updated: 2025/06/19 14:48:14 by xx               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(const char *str, char delimiter)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i] && str[i] != delimiter)
		{
			word_count++;
			while (str[i] && str[i] != delimiter)
				i++;
		}
	}
	return (word_count);
}

static char	*allocate_word(const char *str, int start, int end)
{
	int		i;
	char	*new_word;

	i = 0;
	new_word = malloc(sizeof(char) * (end - start + 1));
	if (!new_word)
		return (NULL);
	while (start < end)
		new_word[i++] = str[start++];
	new_word[i] = '\0';
	return (new_word);
}

static void	free_split_array(char **split_array, int j)
{
	while (j > 0)
		free(split_array[--j]);
	free(split_array);
}

static int	populate_split_array(char **split_array, const char *s,
		char delimiter)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delimiter)
			i++;
		start = i;
		while (s[i] && s[i] != delimiter)
			i++;
		if (start < i)
		{
			split_array[j] = allocate_word(s, start, i);
			if (!split_array[j])
				return (free_split_array(split_array, j), 0);
			j++;
		}
	}
	split_array[j] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split_array;
	int		total_words;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	split_array = malloc(sizeof(char *) * (total_words + 1));
	if (!split_array)
		return (NULL);
	if (!populate_split_array(split_array, s, c))
		return (NULL);
	return (split_array);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
