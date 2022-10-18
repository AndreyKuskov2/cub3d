/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:23:14 by scarob            #+#    #+#             */
/*   Updated: 2021/10/20 21:47:49 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_in_fd(int n, int fd, int i, int result[100])
{
	char	a;

	while (n != 0)
	{
		a = n % 10;
		if (a < 0)
			a *= -1;
		result[i] = a;
		n = n / 10;
		i++;
	}
	while (--i >= 0)
	{
		a = result[i] + 48;
		write(fd, &a, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		result[100];
	int		i;

	i = 0;
	if (n == 0)
	{
		result[0] = 0;
		i++;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	print_in_fd(n, fd, i, result);
}
