/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:22:03 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/10 16:44:46 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;

	if (dest == NULL && src == NULL)
		return (NULL);
	td = (unsigned char *)dest;
	ts = (unsigned char *)src;
	if (td < ts)
		while (n--)
			*td++ = *ts++;
	else
	{
		td = td + n - 1;
		ts = ts + n - 1;
		while (n--)
			*td-- = *ts--;
	}
	return (dest);
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
// // 	int	darr1[] = {1, 2, 15};
// // 	int	sarr1[] = {259, 5, 3555999};
// // 	int	darr2[] = {1, 2, 15};
// // 	int	sarr2[] = {259, 5, 3555999};
// 	int n = 12;

// // 	printmem(darr1, 12);
// // 	printmem(darr2, 12);
// // 	printmem(sarr1, 12);
// // 	printmem(sarr2, 12);

// // 	ft_memmove(darr1, sarr1, n);
// // 	memmove(darr2, sarr2, n);
// // printmem(ft_memcpy(NULL, NULL, n), 12);
// printmem(memcpy(NULL, NULL, n), 12);
// // 	printf(">>>>>>>>>>>>>>>>>>>>>\n");
// // 	printmem(darr1, 12);
// // 	printmem(darr2, 12);
// }