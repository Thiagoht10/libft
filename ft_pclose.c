/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:33:56 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/17 17:32:34 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define POPEN_INTERNAL_BUILD
#include "popen_internal.h"

/**
 * Closes a popen file descriptor.
 *
 * This function closes the file descriptor associated with
 * a child process, waits for that process to finish and
 * removes its entry from the internal popen list. It returns
 * the child exit code, or 128 plus the terminating signal.
 *
 * @param fd The file descriptor returned by ft_popen.
 * @return The child status value, or -1 on error.
 */
int	ft_pclose(int fd)
{
	pid_t	pid;
	int		status;

	pid = get_pid(fd);
	if (pid == -1)
		return (-1);
	close(fd);
	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno != EINTR)
			return (-1);
	}
	if (!remove_list(fd))
		return (-1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (-1);
}
