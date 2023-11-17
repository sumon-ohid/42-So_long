/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumon <sumon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:48:30 by msumon            #+#    #+#             */
/*   Updated: 2023/09/19 07:54:54 by sumon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	sizeinbyte;

	sizeinbyte = nmemb * size;
	p = malloc(sizeinbyte);
	if (p != NULL)
	{
		ft_bzero(p, sizeinbyte);
	}
	return (p);
}
