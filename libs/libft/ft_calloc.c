/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:10:55 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/10 16:50:02 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
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
// 	int	*arr1 = ft_calloc(5, 4);
// 	int	*arr2 = calloc(5, 4);

// 	printmem(arr1, 25);
// 	printmem(arr2, 25);
// }
