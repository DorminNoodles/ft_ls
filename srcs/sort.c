/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:40:12 by lchety            #+#    #+#             */
/*   Updated: 2018/04/13 18:29:27 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*swap(t_info *p1, t_info *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

t_info	*begin_swap(t_info *begin_lst)
{
	if (ft_strcmp(begin_lst->name, begin_lst->next->name) > 0)
		begin_lst = swap(begin_lst, begin_lst->next);
	return (begin_lst);
}

t_info	*lst_sort_ascii(t_info *lst)
{
	t_info	*tmp;
	t_info	*begin_lst;

	begin_lst = lst;
	while (lst->next->next)
	{
		if (ft_strcmp(lst->next->name, lst->next->next->name) > 0)
		{
			lst->next = swap(lst->next, lst->next->next);
			lst = begin_lst;
			if (ft_strcmp(begin_lst->name, begin_lst->next->name) > 0)
				begin_lst = swap(begin_lst, begin_lst->next);
		}
		lst = lst->next;
	}
	return (begin_lst);
}
