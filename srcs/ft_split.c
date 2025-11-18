/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wesperei <wesperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:14:59 by wesperei          #+#    #+#             */
/*   Updated: 2025/11/17 23:14:59 by wesperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_words(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
}

static int	fill_array(char **arr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			arr[idx] = word_dup(s, i, j);
			if (!arr[idx])
				return (idx);
			idx++;
			i = j;
		}
		else
			i++;
	}
	arr[idx] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		res;

	if (!s)
		return (NULL);
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	res = fill_array(arr, s, c);
	if (res != -1)
	{
		free_words(arr, res);
		return (NULL);
	}
	return (arr);
}
