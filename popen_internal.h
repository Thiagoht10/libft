/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popen_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:37:10 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/17 17:11:08 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POPEN_INTERNAL_H
# define POPEN_INTERNAL_H

# ifndef POPEN_INTERNAL_BUILD
#  error "popen_internal.h is private. Include libft.h instead."
# endif

# include <errno.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

typedef struct s_popen_entry
{
	pid_t					pid;
	int						fd;
	struct s_popen_entry	*next;
}							t_popen_entry;

t_popen_entry				**get_list(void);
t_popen_entry				*new_node(pid_t pid, int fd);
int							add_list(pid_t pid, int fd);
int							remove_list(int fd);
pid_t						get_pid(int fd);

#endif
