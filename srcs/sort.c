/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:40:12 by lchety          #+#    #+#             */
/*   Updated: 2018/04/07 18:01:20 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info *swap(t_info *p1, t_info *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}


void lst_sort_ascii(t_dna *dna)
{
	t_info	*tmp;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		tmp = dna->dir_lst;
		swapped = 0;

		if (ft_strcmp(tmp->name, tmp->next->name) < 0)
		{
			swapped = 1;
			dna->dir_lst = swap(tmp, tmp->next);
			tmp = dna->dir_lst;
		}

		while (tmp->next->next)
		{
			if (ft_strcmp(tmp->next->name, tmp->next->next->name) < 0)
			{
				swapped = 1;
				tmp->next = swap(tmp->next, tmp->next->next);
			}
			// ft_printf("first => %s       second => %s \n", tmp->name, tmp->next->name);
			tmp = tmp->next;
		}
	}
}
