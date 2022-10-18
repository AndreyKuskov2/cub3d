/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:15:27 by scarob            #+#    #+#             */
/*   Updated: 2021/10/25 20:01:05 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *str)
{
	int	len;
	int	temp;
	int	i;
	int	j;

	len = ft_strlen(str);
	j = len - 1;
	i = 0;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char	*itoa_one(char *result, int i, int n, int flag)
{
	int	a;
	int	j;

	j = 0;
	while (j <= (i - 1))
	{
		a = n % 10;
		if (a < 0)
			a *= -1;
		result[j] = a + 48;
		n /= 10;
		j++;
	}
	if (flag == 1)
	{
		result[i] = '-';
		result[i + 1] = '\0';
	}
	else
		result[i] = '\0';
	return (result);
}

int	number_of_discharges(int n, int i)
{
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	int		flag;

	i = 0;
	flag = 0;
	if (n == 0)
		i++;
	i = number_of_discharges(n, i);
	if (n >= 0)
		result = (char *)malloc((i + 1) * sizeof(char));
	else
	{
		result = (char *)malloc((i + 2) * sizeof(char));
		flag = 1;
		n *= -1;
	}
	if (!result)
		return (0);
	result = itoa_one(result, i, n, flag);
	return (ft_reverse(result));
}
