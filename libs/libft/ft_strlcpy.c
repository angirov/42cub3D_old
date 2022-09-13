/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:09:10 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/02 22:06:43 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	return_value;

	return_value = ft_strlen(src);
	if (size > 0)
	{
		while (size-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (return_value);
}

// #include <stdio.h>
// #include <bsd/string.h> 
// int	main()
// {
// 	char real_dest[6] = "hello";
// 	char real_sorce[20] = "BuyBuyBuyBuy";
// 	char fake_dest[6] = "hello";
// 	char fake_sorce[20] = "BuyBuyBuyBuy";
// 	// the size considers the null-terminator, 
// 	// if 1, only NT is copied, if 2, only the first char
// 	// size_t	testsize = 12; 

// 	printf("Real function >>>>>\n");
// 	// printf("%ld\n", strlcpy(real_dest, real_sorce, testsize));
// 	printf("%ld\n", strlcpy(real_dest, real_sorce, sizeof(real_dest)));
// 	printf("%s\n", real_dest);
// 	printf("Fake function >>>>>\n");
// 	// printf("%ld\n", ft_strlcpy(fake_dest, fake_sorce, testsize));
// 	printf("%ld\n", ft_strlcpy(fake_dest, fake_sorce, sizeof(fake_dest)));
// 	printf("%s\n", fake_dest);
// }
