/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:09:24 by andcarva          #+#    #+#             */
/*   Updated: 2024/12/18 20:38:41 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_s(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_str(char const *s, char c)
{
	size_t	count;
	size_t	word;

	word = 0;
	count = 0;
	while (s && *s)
	{
		while (*s != c && word == 0)
		{
			word = 1;
			count++;
		}
		if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	size_t	len;
	char	*new_word;
	size_t	i;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	new_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_word[i] = s[i];
		i++;
	}
	new_word[len] = '\0';
	return (new_word);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	i;

	i = 0;
	split = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!split)
		return (NULL);
	while (s && *s != '\0')
	{
		if (*s != c)
		{
			split[i] = get_word(s, c);
			if (!split[i])
				return (free_s(split), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}
