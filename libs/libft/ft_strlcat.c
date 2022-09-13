/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:09:10 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/02 22:07:23 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	return_value;

	if (ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	return_value = ft_strlen(src) + ft_strlen(dst);
	while (*dst && size-- > 0)
		dst++;
	if (size >= 2)
	{
		while (size-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (return_value);
}

// #include <bsd/string.h> 
// #include <stdio.h>
// int	main()
// {
// 	char real_dest[8] = "hello";
// 	char real_sorce[20] = "BuyBuyBuyBuy";
// 	char fake_dest[8] = "hello";
// 	char fake_sorce[20] = "BuyBuyBuyBuy";
// 	// the size considers the null-terminator, 
// 	// if 1, only NT is copied, if 2, only the first char
// 	// size_t	testsize = 12; 
// 	printf("Real function >>>>>\n");
// 	// printf("%ld\n", strlcat(real_dest, real_sorce, testsize));
// 	printf("%ld\n", strlcat(real_dest, real_sorce, 3)); //sizeof(real_dest)));
// 	printf("%s\n", real_dest);
// 	printf("Fake function >>>>>\n");
// 	// printf("%ld\n", ft_strlcat(fake_dest, fake_sorce, testsize));
// 	printf("%ld\n", ft_strlcat(fake_dest, fake_sorce, 3));//sizeof(fake_dest)))
// 	printf("%s\n", fake_dest);
// }
