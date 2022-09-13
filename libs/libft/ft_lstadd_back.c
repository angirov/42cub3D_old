/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:14:20 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/16 22:42:41 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old_last;

	old_last = *lst;
	if (old_last)
	{
		old_last = ft_lstlast(*lst);
		(old_last)->next = new;
	}
	else
		*lst = new;
}
