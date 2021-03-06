/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:37:48 by lchety            #+#    #+#             */
/*   Updated: 2018/08/27 18:58:38 by lchety           ###   ########.fr       */
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
#define RECURSIVE 8
#define TRI_DATE 16

#define STRING_OPT "-1acdilqrtuCFR"

#define USAGE USAGE_LINE_1 USAGE_LINE_2
#define USAGE_LINE_1 "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] "
#define USAGE_LINE_2 "[file ...]\n"

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
	t_info	*dir_lst_params;
	int		options;
} t_dna;


int			ft_printf(const char *format, ...);
t_info		*lst_sort_ascii(t_info *lst);
void 		parsing(t_dna *dna, int argc, char **argv);
void 		display(t_dna *dna);
void 		error(char *str);
void		display_lst_dir(t_dna *dna, t_info *lst);
void		create_dir_lst(t_dna *dna, char *path);
int			isHidden(char *str);
