/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:37:48 by lchety            #+#    #+#             */
/*   Updated: 2018/03/01 13:39:52 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

#define LONG_FORMAT 1
#define REVERSE 2
#define HIDDEN 4
#define RECURSIVE 6

typedef struct s_info
{
	char			name[255];
	int				atime;
	int				mtime;
	int				ctime;
	int				size;
	int				nblink;
	int				protection;
	struct s_info	*next;
} t_info;

typedef struct	s_dna
{
	t_info	*dir_lst;
	int		options;
} t_dna;


int				ft_printf(const char *format, ...);
void lst_sort_ascii(t_dna *dna);
