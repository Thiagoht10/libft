/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:46:17 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 21:30:42 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets a block of memory to zero.
 *
 * This function fills the first n bytes of the memory area pointed to by s
 * with zeroes. It is typically used to initialize or clear memory.
 *
 * @param s The memory area to be cleared.
 * @param n The number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	unsigned char	*us;

	us = s;
	a = 0;
	while (a < n)
	{
		us[a] = 0;
		a++;
	}
}

/*int     main(void)
{
        int     a;
        char    str1[10] = "123456789";
        char    str2[10] = "123456789";

        bzero(str1, 4);
        ft_bzero(str2, 4);
        a = 0;
        while (a < 10)
        {
                printf("%d ", str1[a]);
                a++;
        }
        a = 0;
        printf("\n");
        while (a < 10)
        {
                printf("%d ", str2[a]);
                a++;
        }
        return (0);
}*/
