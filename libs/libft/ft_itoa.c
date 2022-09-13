/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:49:18 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/10 22:34:18 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long num)
{
	int	len;

	if (num == 0)
		return (1);
	if (num < 0)
		len = 1;
	else
		len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	int		len;
	int		i;

	num = n;
	len = ft_intlen(num);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		i = 1;
		num *= -1;
	}
	else
		i = 0;
	str[len--] = '\0';
	while (len >= i)
	{
		str[len--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	int num = -123;

// 	printf("len = %d\n", ft_intlen(num));
// 	printf("%s\n", ft_itoa(num));
// }