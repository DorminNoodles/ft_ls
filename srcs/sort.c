/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:40:12 by lchety            #+#    #+#             */
/*   Updated: 2018/04/12 18:42:57 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info	*swap(t_info *p1, t_info *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

t_info	*lst_sort_ascii(t_info *lst)
{
	t_info	*tmp;
	t_info	*begin_lst;
	int		swapped;

	swapped = 1;
	begin_lst = lst;
	while (swapped)
	{
		tmp = begin_lst;
		swapped = 0;

		if (tmp->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				printf("HEEEEERRRRREEE\n");
				begin_lst = swap(tmp, tmp->next);
			}
			else
			{
				while (tmp->next)
				{
					tmp = tmp->next;
				}
			}
		}
	}
	printf(">>>> %s\n", begin_lst->name);
	return (begin_lst);
}

// t_info	*lst_sort_ascii(t_info *lst)
// {
// 	t_info	*tmp;
// 	t_info	*begin_lst;
// 	int		swapped;
//
// 	swapped = 1;
// 	begin_lst = lst;
// 	while (swapped)
// 	{
// 		tmp = begin_lst;
// 		swapped = 0;
//
//
// 		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
// 		{
// 			swapped = 1;
// 			begin_lst = swap(tmp, tmp->next);
// 			tmp = begin_lst;
// 		}
//
// 		while (tmp->next->next)
// 		{
// 			if (ft_strcmp(tmp->next->name, tmp->next->next->name) < 0)
// 			{
// 				swapped = 1;
// 				tmp->next = swap(tmp->next, tmp->next->next);
// 			}
// 			tmp = tmp->next;
// 		}
// 	}
// 	return (begin_lst);
// }
