/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:23:08 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/17 18:29:05 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies the current process environment.
 *
 * @return A newly allocated copy of the environment.
 */
char	**ft_get_env(void)
{
	extern char	**environ;

	if (!environ)
		return (NULL);
	return (ft_vetor_dup(environ));
}
