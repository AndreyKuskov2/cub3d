/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:24:56 by scarob            #+#    #+#             */
/*   Updated: 2021/10/25 20:12:35 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_in_str(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
}

char	*split1(char *result, size_t first_l, size_t final_l, char const *s)
{
	size_t	k;

	k = 0;
	result = (char *)malloc((final_l - first_l + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (first_l < final_l)
	{
		result[k] = s[first_l];
		k++;
		first_l++;
	}
	result[k] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	k[2];
	size_t	first_l;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc((words_in_str(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	k[0] = 0;
	k[1] = 0;
	while (s[k[0]] != '\0')
	{
		if (s[k[0]] == c)
			k[0]++;
		else
		{
			first_l = k[0];
			while (s[k[0]] != c && s[k[0]] != '\0')
				k[0]++;
			result[k[1]] = split1(result[k[1]], first_l, k[0], s);
			k[1]++;
		}
	}
	return (result);
}
