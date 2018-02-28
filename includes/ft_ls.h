/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:37:48 by lchety            #+#    #+#             */
/*   Updated: 2018/02/28 01:15:39 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"


typedef struct s_info
{
	char	name[255];
	int		atime;
	int		mtime;
	int		ctime;
	int		blksize;
} t_info;

typedef struct	s_dna
{
	t_info	*dir_lst;
} t_dna;


int				ft_printf(const char *format, ...);
