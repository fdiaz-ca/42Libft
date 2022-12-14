/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:10:11 by fdiaz-ca          #+#    #+#             */
/*   Updated: 2022/09/26 19:38:25 by fdiaz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst)
	{
		if ((*lst)->next == NULL)
		{
			del(((*lst))->content);
			free(*lst);
			*lst = NULL;
		}
		else
		{
			ft_lstclear(&((*lst)->next), del);
			del((*lst)->content);
			free(*lst);
			*lst = NULL;
		}
	}
}
