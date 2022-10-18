/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarob <scarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:26:39 by scarob            #+#    #+#             */
/*   Updated: 2021/10/22 22:01:17 by scarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*buf;
	int		i;

	i = 0;
	while (lst)
	{
		if (i == 0)
		{
			new_list = ft_lstnew(f(lst->content));
			if (!new_list)
				return (NULL);
		}
		else
		{
			buf = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new_list, buf);
		}
		lst = lst->next;
		i++;
	}
	ft_lstclear(&lst, del);
	return (new_list);
}
