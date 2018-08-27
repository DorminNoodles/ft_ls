/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:42:58 by lchety            #+#    #+#             */
/*   Updated: 2018/08/27 02:12:49 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//0 == pas d options on passe au folder -1 == error crash
int		check_options(char *str)
{
	int i;

	i = 0;
	if (str[0] != '-' || (str[0] == '-' && str[1] == '-'))
		return (0);
	while (str[i])
	{
		if (!ft_strchr(STRING_OPT, str[i]))
		{
			ft_printf("ls: illegal option -- %c\n", str[i]);
			error(USAGE);
		}
		i++;
	}
	return (1);
}

int		get_folder(t_dna *dna, char *str)
{
	t_info	*tmp;
	t_info	*lst;

	lst = dna->dir_lst_params;
	tmp = ft_memalloc(sizeof(t_info*));
	ft_strcpy(tmp->name, str);

	if (!dna->dir_lst_params)
	{
		dna->dir_lst_params = tmp;
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = tmp;
	}
	return (1);
}

void	get_options(t_dna *dna, char *str)
{
		if (ft_strchr(str, 'R'))
			dna->options = dna->options | RECURSIVE;
		if (ft_strchr(str, 'l'))
			dna->options = dna->options | LONG_FORMAT;
		if (ft_strchr(str, 'a'))
			dna->options = dna->options | HIDDEN;
		if (ft_strchr(str, 'r'))
			dna->options = dna->options | REVERSE;
		if (ft_strchr(str, 't'))
			dna->options = dna->options | TRI_DATE;
}

void	parsing(t_dna *dna, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc && check_options(argv[i]))
	{
		get_options(dna, argv[i]);
		printf("}****coucou****{\n");
		// if (argv[i][0] == '-')
		// 	paring_options(argv[i]);
		i++;
	}

	while (i < argc && get_folder(dna, argv[i]))
	{
		printf("}***get_folder***{\n");
		// if (argv[i][0] == '-')
		// 	paring_options(argv[i]);
		i++;
	}
}
