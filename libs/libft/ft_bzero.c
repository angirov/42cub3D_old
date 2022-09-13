/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:09:11 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/08 20:13:11 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ts;

	ts = (unsigned char *)s;
	while (n--)
		(*ts++ = 0);
}

// #include <stdio.h>
// #include <string.h>
// void	printmem(const void *s, size_t n)
// {
// 	unsigned char	*t;

// 	if (!s)
// 		printf("You've passed a null pointer!\n");
// 	else
// 	{
// 		t = (unsigned char *)s;
// 		while (n-- > 0)
// 			printf("%02x ", *t++);
// 		printf("\n");
// 	}
// }

// int	main()
// {
// 	int	arr1[] = {259, 5, 3555999};
// 	int	arr2[] = {259, 5, 3555999};
// 	int	n = 0;

// 	printmem(arr1, 12);
// 	printmem(arr2, 12);

// 	ft_bzero(arr1, n);
// 	bzero(arr2, n);

// 	printf(">>>>>>>>>>>>>\n");
// 	printmem(arr1, 12);
// 	printmem(arr2, 12);
// }
