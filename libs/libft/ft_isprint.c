/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:20:32 by vangirov          #+#    #+#             */
/*   Updated: 2021/12/02 20:47:22 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     char c = '3';
//     if (ft_isalpha(c))
//         printf("%c is alpha\n", c);
//     else
//         printf("%c is not alpha\n", c);
//     return (0);
// }
