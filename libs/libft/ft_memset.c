/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:47:02 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/11 18:03:05 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	tc;
	unsigned char	*ts;

	tc = (unsigned char)c;
	ts = (unsigned char *)str;
	while (n--)
		*ts++ = tc;
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// void	printmem(const void *s, size_t n)
// {
// 	unsigned char	*t;

// 	t = (unsigned char *)s;
// 	while (n-- > 0)
// 		printf("%02x ", *t++);
// 	printf("\n");
// }

// int	main()
// {
// 	int		arr1[] = {1, 2, 15};
// 	int		arr2[] = {1, 2, 15};
// 	int	c = 257;
// 	int		n = 12;

// 	printmem(arr1, 12);
// 	printmem(arr2, 12);

// 	ft_memset(arr1, c, n);
// 	memset(arr2, c, n);

// 	printmem(arr1, 12);
// 	printmem(arr2, 12);
// }
