/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:33:51 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/17 17:32:51 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define POPEN_INTERNAL_BUILD
#include "popen_internal.h"

/**
 * Returns the internal popen list.
 *
 * This function returns the address of the singleton list
 * head used to store popen file descriptors and child pids.
 *
 * @return The address of the internal list head.
 */
t_popen_entry	**get_list(void)
{
	static t_popen_entry	*list;

	return (&list);
}

/**
 * Creates a new popen list node.
 *
 * This function allocates and initializes a node with the
 * child pid and the file descriptor returned by ft_popen.
 *
 * @param pid The child process id.
 * @param fd The file descriptor associated with the child.
 * @return A new node, or NULL on allocation failure.
 */
t_popen_entry	*new_node(pid_t pid, int fd)
{
	t_popen_entry	*node;

	node = malloc(sizeof(t_popen_entry));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->pid = pid;
	node->next = NULL;
	return (node);
}

/**
 * Adds an entry to the internal popen list.
 *
 * This function creates a new node with the given pid and fd,
 * then appends it to the end of the internal popen list.
 *
 * @param pid The child process id.
 * @param fd The file descriptor associated with the child.
 * @return TRUE on success, or FALSE on allocation failure.
 */
int	add_list(pid_t pid, int fd)
{
	t_popen_entry	*n_node;
	t_popen_entry	**list;
	t_popen_entry	*tmp;

	n_node = new_node(pid, fd);
	if (!n_node)
		return (FALSE);
	list = get_list();
	if (!*list)
	{
		*list = n_node;
		return (TRUE);
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n_node;
	return (TRUE);
}

/**
 * Removes an entry from the internal popen list.
 *
 * This function searches for the node associated with fd,
 * unlinks it from the list and frees its memory.
 *
 * @param fd The file descriptor associated with the entry.
 * @return TRUE if the entry was removed, FALSE otherwise.
 */
int	remove_list(int fd)
{
	t_popen_entry	**list;
	t_popen_entry	*tmp;
	t_popen_entry	*prev;

	list = get_list();
	tmp = *list;
	prev = NULL;
	while (tmp && tmp->fd != fd)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return (FALSE);
	if (!prev)
		*list = tmp->next;
	else
		prev->next = tmp->next;
	free(tmp);
	return (TRUE);
}

/**
 * Gets the child pid associated with a file descriptor.
 *
 * This function searches the internal popen list for fd and
 * returns the child pid stored in the matching node.
 *
 * @param fd The file descriptor returned by ft_popen.
 * @return The child process id, or -1 if fd is not found.
 */
pid_t	get_pid(int fd)
{
	t_popen_entry	**list;
	t_popen_entry	*tmp;

	list = get_list();
	tmp = *list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
		return (-1);
	return (tmp->pid);
}
