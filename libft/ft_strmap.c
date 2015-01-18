/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:28:56 by pxia              #+#    #+#             */
/*   Updated: 2014/11/10 18:10:12 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(const char *s, char (*f)(char))
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	i = 0;
	l = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (l + 1));
	while (i < l)
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
