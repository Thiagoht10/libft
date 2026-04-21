/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_failed_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 00:42:13 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 21:35:18 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Frees a partially allocated string vector.
 * 
 * This function frees each string in the vector up to the given
 * index, then frees the vector itself and sets it to NULL.
 * 
 * @param vector A pointer to the string array to be freed.
 * @param idx The number of elementes to free.
 */
void	free_failed_vector(char ***vector, int idx)
{
	int	i;

	if (!vector || !*vector)
		return ;
	i = 0;
	while (i < idx)
	{
		free((*vector)[i]);
		(*vector)[i] = NULL;
		i++;
	}
	free(*vector);
	*vector = NULL;
}
