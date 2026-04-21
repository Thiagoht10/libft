/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:16:39 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 22:35:36 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates over a list and applies a function to each node.
 * 
 * This functions traverses the list and applies the given
 * function to the content of each node.
 * 
 * @param lst The list to iterate over.
 * @param f The function to apply to each content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void	lst_f(void *content)
{
	int		a;
	char	*str;

	a = 0;
	str = (char *)content;
	while (str[a] != '\0')
	{
		if (str[a] >= 'a' && str[a] <= 'z')
			str[a] -= 32;
		a++;
	}
} */

/* void    lst_f(void *content);

int	main(void)
{
        t_list  *n1;
        t_list  *n2;
        t_list  *n3;

        n1 = ft_lstnew(ft_strdup("No um"));
        n2 = ft_lstnew(ft_strdup("No dois"));
        n3 = ft_lstnew(ft_strdup("No tres"));
        ft_lstadd_back(&n1, n2);
        ft_lstadd_back(&n1, n3);
        ft_lstiter(n1, lst_f);
        printf("%s\n", (char *)(n3->content));
        ft_lstclear(&n1, free);
        return (0);
} */
