/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:38:50 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/17 18:52:28 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates a file descriptor and closes the old one.
 *
 * This function duplicates oldfd into newfd. If successful,
 * it closes oldfd and returns newfd. On failure, it returns -1.
 *
 * @param oldfd The file descriptor to duplicate.
 * @param newfd The target file descriptor.
 * @return The new file descriptor on success, or -1 on failure.
 */
int	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		return (-1);
	if (oldfd != newfd)
		close(oldfd);
	return (newfd);
}
