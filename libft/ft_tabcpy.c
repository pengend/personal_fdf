/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:16:49 by pxia              #+#    #+#             */
/*   Updated: 2014/11/16 18:30:40 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void ft_tabcpy(char **dest, char **tab, size_t tablen)
{
	unsigned int i;

	if (*tab == NULL || tablen == 0)
		return ;
	i = 0;
	while (i < tablen)
	{
		dest[i] = tab[i];
		i++;
	}
}
