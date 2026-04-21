/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:24:36 by thiago            #+#    #+#             */
/*   Updated: 2026/04/21 22:57:15 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Free up memory and set the pointer to null.
 * 
 * This function frees the memory pointed to by the given
 * pointer and sets it to NULL to avoid dangling pointers.
 * 
 * @param prt A pointer to a void pointer.
 */
void	ft_memdel(void **prt)
{
	if (prt && *prt)
	{
		free(*prt);
		*prt = NULL;
	}
}
