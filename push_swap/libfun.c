/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: e <e@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:34:29 by e                 #+#    #+#             */
/*   Updated: 2025/02/20 14:37:30 by e                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	char	*word;
	int		i;

	words_count = count_words(s, c);
	result_array = malloc(sizeof(char *) * (words_count + 1));
	if (!result_array)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		word = get_next_word(s, c);
		if (!word)
		{
			free_split(result_array);
			return (NULL);
		}
		result_array[i++] = word;
	}
	result_array[i] = NULL;
	return (result_array);
}

long int	ft_atol(const char *c)
{
	int			a;
	int			j;
	long int	res;
	int			si;

	a = 0;
	res = 0;
	j = 0;
	si = 1;
	while (c[a] == ' ' || c[a] == '\t' || c[a] == '\n'
		|| c[a] == '\v' || c[a] == '\f' || c[a] == '\r')
		a++;
	while (c[a] == '-' || c[a] == '+')
	{
		if (c[a] == '-')
			si = si * -1;
		a++;
		j++;
	}
	while (c[a] >= '0' && c[a] <= '9')
		res = res * 10 + (c[a++] - '0');
	if (j > 1)
		return (0);
	return (res * si);
}
