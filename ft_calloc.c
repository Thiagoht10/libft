/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:28:41 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 21:30:51 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Frees two memory pointers and sets them to NULL.
 *
 * This function calls ft_memdel on both provided pointers, freeing
 * the allocated memory they point to and setting them to NULL.
 *
 * @param prt1 The first pointer to be freed.
 * @param prt2 The second pointer to be freed.
 */
void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*arr;
	size_t	bytes;

	if (size != 0 && SIZE_MAX / size < nmenb)
		return (NULL);
	bytes = nmenb * size;
	arr = malloc(bytes);
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, bytes);
	return (arr);
}

/*int     main(void)
{
	int     a = 0;
        int     z = 4;
        char     *arr = ft_calloc(z, sizeof(int));
        
        while (a < z)
        {       
                if (arr != NULL)
                        printf("%d", arr[a]);
                a++;
        }
        return (0);
}*/
