/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:01:55 by lspazzin          #+#    #+#             */
/*   Updated: 2021/05/18 14:25:09 by lodovico         ###   ########.fr       */
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
	if (&tdest[i] == NULL && (void *)&tsrc[i] == NULL)
		return (NULL);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dst);
}
