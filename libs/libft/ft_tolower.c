/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:54:41 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/02 22:10:18 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include <ctype.h> 
// #include <stdio.h>
// int	main()
// {
// 	char	test;
// 	char	c1;
// 	char	c2;

// 	test = 'C';
// 	c1 = test;
// 	c2 = test;
// 	printf("Real function:\n");
// 	printf("%c\n", tolower(c1));
// 	printf("Fake function:\n");
// 	printf("%c\n", ft_tolower(c2));
// }
