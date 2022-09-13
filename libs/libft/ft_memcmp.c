/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:26:46 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/10 16:43:14 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && *t1 == *t2)
	{
		t1++;
		t2++;
	}
	return (*t1 - *t2);
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
// 	int	arr1[] = {1, 2, 15};
// 	int	arr2[] = {259, 5, 3};
// 	int n = 2;

// 	printmem(arr1, 12);
// 	printmem(arr2, 12);

// 	printf("%d\n", ft_memcmp(arr1, arr2, n));
// 	printf("%d\n", memcmp(arr1, arr2, n));
// }
