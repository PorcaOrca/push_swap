/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:01:55 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:22:47 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tdest;
	unsigned const char	*tsrc;

	i = 0;
	tdest = (unsigned char *)dst;
	tsrc = (unsigned const char *)src;
	if (&dst[i] == NULL && (void *)&src[i] == NULL)
		return (NULL);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dst);
}
