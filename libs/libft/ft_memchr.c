/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:35:13 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/10 01:02:52 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned char	tc;

	ts = (unsigned char *)s;
	tc = (unsigned char)c;
	while (n--)
		if (*ts++ == tc)
			return (ts - 1);
	return (NULL);
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
// 	int	c = 66;
// 	int	n = 33;

// 	printmem(arr1, 12);
// 	printmem(arr2, 12);

// 	int	*newarr1 = ft_memchr(arr1, c, n);
// 	int	*newarr2 = memchr(arr2, c, n);

// 	printf(">>>>>>>>>>>>>\n");
// 	printmem(newarr1, 12);
// 	printmem(newarr2, 12);
// }
