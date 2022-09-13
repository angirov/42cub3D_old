/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:48:58 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/16 22:35:37 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_list;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
	{
		ft_lstclear(&ret_list, del);
		return (NULL);
	}
	ret_list = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = ft_lstnew(f(lst->content));
		ft_lstadd_back(&ret_list, temp);
		temp = temp -> next;
	}
	return (ret_list);
}
