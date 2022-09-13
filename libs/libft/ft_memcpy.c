/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:22:13 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/18 16:18:16 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*td;
	char	*ts;

	if (dest == NULL && src == NULL)
		return (NULL);
	td = (char *)dest;
	ts = (char *)src;
	while (n--)
		*td++ = *ts++;
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

// }

// //   abcdef

// // S abcd
// // D   cdef 

// // R ababab
