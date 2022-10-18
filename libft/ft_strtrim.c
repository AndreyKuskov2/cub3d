/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:47:12 by scarob            #+#    #+#             */
/*   Updated: 2021/10/19 18:48:05 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	first_symbol_in_str(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	while (s1[i])
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	final_symbol_in_str(char const *s1, char const *set)
{
	size_t	len;
	size_t	j;
	size_t	flag;

	len = ft_strlen(s1) - 1;
	while (len > 0)
	{
		j = 0;
		flag = 0;
		while (set[j])
		{
			if (s1[len] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
			len--;
		else
			break ;
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	first_symbol;
	size_t	final_symbol;
	size_t	i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	first_symbol = first_symbol_in_str(s1, set);
	final_symbol = final_symbol_in_str(s1, set);
	if (first_symbol > final_symbol)
		return (ft_strdup(""));
	result = (char *)malloc((final_symbol - first_symbol + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (first_symbol < final_symbol)
	{
		result[i] = s1[first_symbol];
		first_symbol++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
