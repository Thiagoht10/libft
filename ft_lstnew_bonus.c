/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago <thiago@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:55:46 by thde-sou          #+#    #+#             */
/*   Updated: 2026/04/21 22:45:46 by thiago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Creates a new list node.
 * 
 * This function allocates memory for a new node, sets its
 * content, and initializes the next pointer to NULL.
 * 
 * @param content The content to store in the node.
 * @return The new node, or NULL on failure.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int     main(void)
{        
        t_list  *nodo;
        int     valor = 42;
        nodo = ft_lstnew(&valor);
        if (nodo)
                printf("conteudo do nó: %d\n", *(int *)(nodo->content));
        free(nodo);
        return (0);
} */
