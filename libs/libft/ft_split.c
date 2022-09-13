/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:48:39 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/08 21:18:26 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toknum(const char *str, char c)
{
	int	num;
	int	intoken;

	num = 0;
	intoken = 0;
	while (*str)
	{
		if (*str != c && intoken == 0)
		{
			num++;
			intoken = 1;
		}
		else if (*str == c && intoken == 1)
			intoken = 0;
		str++;
	}
	return (num);
}

static int	ft_toklen(const char *s, char c)
{
	int	toklen;

	toklen = 0;
	while (*s != c && *s != '\0')
	{
		toklen++;
		s++;
	}
	return (toklen);
}

static char	*ft_allocstr(const char *s, int toklen)
{
	char	*newstr;
	char	*ptr;

	newstr = (char *)malloc((toklen + 1) * sizeof(char));
	ptr = newstr;
	while (toklen--)
	{
		*ptr++ = *s++;
	}
	*ptr = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	int		toknum;
	int		toklen;
	char	**arr;
	int		i;

	if (!s)
		return (0);
	toknum = ft_toknum(s, c);
	arr = (char **)malloc((toknum + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			toklen = ft_toklen(s, c);
			arr[i++] = ft_allocstr(s, toklen);
			s += toklen;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// #include <stdio.h>
// int	main()
// {
// 	char	str[] ="_11__22__33_";
// 	char	c = '_';
// 	char	**arr;
// 	int		toknum;

// 	toknum = ft_toknum(str, c);
// 	arr = ft_split(str, c);
// 	for (int i = 0; i <= toknum; i++)
// 		printf(">>> %s\n", arr[i]);
// }
