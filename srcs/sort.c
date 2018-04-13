/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:40:12 by lchety            #+#    #+#             */
/*   Updated: 2018/04/13 15:20:42 by lchety           ###   ########.fr       */
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

	// p1->next = p2->next;
	// p2->next = p1;
	return (begin_lst);
}

t_info	*lst_sort_ascii(t_info *lst)
{
	t_info	*tmp;
	t_info	*begin_lst;
	int		swapped;

	swapped = 1;
	begin_lst = lst;

	t_info *fuck;
	fuck = lst;
	while (fuck)
	{
		printf("%s\n", fuck->name);
		fuck = fuck->next;
	}

	printf("\n\n\n");
	while (lst->next->next)
	{
		if (ft_strcmp(lst->next->name, lst->next->next->name) > 0)
		{
			printf("swap   %s   <->   %s\n", lst->next->name, lst->next->next->name);
			lst->next = swap(lst->next, lst->next->next);
			lst = begin_lst;
			begin_lst = begin_swap(begin_lst);
		}

		// begin_lst = begin_swap(begin_lst);
		lst = lst->next;
	}
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
