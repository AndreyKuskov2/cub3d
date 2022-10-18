/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:31:31 by scarob            #+#    #+#             */
/*   Updated: 2021/10/19 18:31:32 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_src;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	copy_src = (char *)malloc(len + 1);
	if (!copy_src)
		return (NULL);
	while (s1[i])
	{
		copy_src[i] = s1[i];
		i++;
	}
	copy_src[i] = '\0';
	i = 0;
	while (copy_src[i] != '\0' || s1[i] != '\0')
	{
		if (s1[i] != copy_src[i])
			return (NULL);
		i++;
	}
	return (copy_src);
}
