/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wesperei <wesperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:53:26 by wesperei          #+#    #+#             */
/*   Updated: 2025/11/17 22:53:26 by wesperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			total;
	size_t			i;

	total = count * size;
	p = (unsigned char *)malloc(total);
	if (!p)
		return (0);
	i = 0;
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
