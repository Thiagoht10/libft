/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:22:49 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 21:59:51 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a string contains only numeric digits.
 * 
 * This function returns 1 if all characters in the string
 * are digits (0-9), and 0 otherwise. Returns 0 if str is NULL.
 * 
 * @param str The string to be checked.
 * @return 1 if numeric, 0 otherwise.
 */
int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
