/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:41:32 by scarob            #+#    #+#             */
/*   Updated: 2021/10/20 18:40:47 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*new_str;
	size_t		i;

	new_str = (char *)haystack;
	i = ft_strlen(needle);
	if (*needle == 0)
		return (new_str);
	while (*new_str)
	{
		if (ft_memcmp(new_str, needle, i) == 0)
			return (new_str);
		if (len == 0)
			return (NULL);
		len--;
		new_str++;
		if (len < 1 || i > len)
			return (NULL);
	}
	return (NULL);
}
