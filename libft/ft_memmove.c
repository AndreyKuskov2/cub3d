/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:19:42 by scarob            #+#    #+#             */
/*   Updated: 2021/10/19 18:19:43 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	a;

	a = 1;
	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (src < dst)
	{
		a = -1;
		i = len - 1;
	}
	while (len--)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i += a;
	}
	return (dst);
}
