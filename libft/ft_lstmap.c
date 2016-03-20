/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:15:50 by jdhaisne          #+#    #+#             */
/*   Updated: 2015/12/03 12:10:58 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *ptr;
	t_list *ptr2;

	result = NULL;
	if (lst == NULL || (*f) == NULL)
		return (NULL);
	ptr2 = (*f)(lst);
	if ((result = ft_lstnew(ptr2->content, ptr2->content_size)) != NULL)
	{
		ptr = result;
		lst = lst->next;
		while (lst != NULL)
		{
			ptr2 = (*f)(lst);
			if (!(ptr->next = ft_lstnew(ptr2->content, ptr2->content_size)))
				return (NULL);
			ptr = ptr->next;
			lst = lst->next;
		}
	}
	return (result);
}
