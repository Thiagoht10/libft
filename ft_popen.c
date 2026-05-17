/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:34:02 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/17 18:55:51 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define POPEN_INTERNAL_BUILD
#include "popen_internal.h"
#include "libft.h"

/**
 * Closes valid pipe file descriptors.
 *
 * This function closes both file descriptors stored in fd
 * when they contain valid open descriptors.
 *
 * @param fd The pipe file descriptor array.
 */
static void	cleanup(int fd[2])
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
}

/**
 * Executes a command in the child process.
 *
 * This function redirects the pipe according to the popen
 * mode and executes the command through /bin/sh.
 *
 * @param command The shell command line to execute.
 * @param type The popen mode, either 'r' or 'w'.
 * @param fd The pipe file descriptor array.
 */
static void	child_popen(const char *command, const char type, int fd[2])
{
	if (type == 'r')
	{
		if (ft_dup2(fd[1], STDOUT_FILENO) == -1)
		{
			cleanup(fd);
			exit(EXIT_FAILURE);
		}
	}
	else if (type == 'w')
	{
		if (ft_dup2(fd[0], STDIN_FILENO) == -1)
		{
			cleanup(fd);
			exit(EXIT_FAILURE);
		}
	}
	execl("/bin/sh", "sh", "-c", command, (char *) NULL);
	if (type == 'w')
		close(STDIN_FILENO);
	else if (type == 'r')
		close(STDOUT_FILENO);
	exit(127);
}

/**
 * Executes a shell command with a pipe.
 *
 * This function creates a pipe, forks a child process and
 * returns a file descriptor connected to the command input
 * or output, according to the given popen mode.
 *
 * @param command The shell command line to execute.
 * @param type The popen mode, either 'r' or 'w'.
 * @return A pipe file descriptor, or -1 on error.
 */
int	ft_popen(const char *command, const char type)
{
	pid_t	pid;
	int		fd[2];

	if (!command || (type != 'w' && type != 'r'))
		return (-1);
	fd[0] = -1;
	fd[1] = -1;
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (cleanup(fd), -1);
	if (pid == 0)
		child_popen(command, type, fd);
	if (type == 'r')
	{
		close(fd[1]);
		if (!add_list(pid, fd[0]))
			return (cleanup(fd), -1);
		return (fd[0]);
	}
	close(fd[0]);
	if (!add_list(pid, fd[1]))
		return (cleanup(fd), -1);
	return (fd[1]);
}
