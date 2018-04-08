/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:42:58 by lchety            #+#    #+#             */
/*   Updated: 2018/04/08 18:42:36 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void parsing(t_dna *dna, int argc, char **argv)
{
	if (ft_strargv(argc, argv, "-R"))
		dna->options = dna->options | RECURSIVE;
	if (ft_strargv(argc, argv, "-l"))
		dna->options = dna->options | LONG_FORMAT;
	if (ft_strargv(argc, argv, "-a"))
		dna->options = dna->options | HIDDEN;
	if (ft_strargv(argc, argv, "-r"))
		dna->options = dna->options | REVERSE;
	if (ft_strargv(argc, argv, "-t"))
		dna->options = dna->options | TRI_DATE;
}
