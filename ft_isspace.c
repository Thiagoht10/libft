/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 00:59:44 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 22:05:05 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a character is a whitespace.
 * 
 * This function returns 1 if character is a whitespace
 * (space or ASCII 9 to 13), and 0 otherwise.
 * 
 * @param c The character to be checked.
 * @return 1 if whitespace, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
