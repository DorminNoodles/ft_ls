/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 21:45:50 by lchety            #+#    #+#             */
/*   Updated: 2018/04/08 14:42:27 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display(t_dna *dna)
{
	t_info	*tmp;

	tmp = dna->dir_lst;

	while (tmp)
	{
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

void display_lst_dir(t_info *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->name);
		lst = lst->next;
	}
}
