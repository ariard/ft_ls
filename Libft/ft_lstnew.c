/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:41:03 by ariard            #+#    #+#             */
/*   Updated: 2016/11/23 16:33:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;
	void	*tmp;

	if (!(node = (t_list *)malloc(sizeof(t_list) * (content_size + 1))))
		return (NULL);
	node->next = NULL;
	if (content)
	{
		if (!(tmp = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(tmp, content, content_size);
		node->content = tmp;
		node->content_size = content_size;
	}
	else
	{
		node->content = NULL;
		node->content_size = 0;
	}
	return (node);
}
