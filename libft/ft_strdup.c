/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:35:18 by pxia              #+#    #+#             */
/*   Updated: 2014/11/08 20:52:29 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*tmp;

	if ((tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (tmp);
	ft_strcpy(tmp, s);
	return (tmp);
}
