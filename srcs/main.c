/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:14:06 by lchety            #+#    #+#             */
/*   Updated: 2018/03/01 15:42:44 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_ls.h"


void opendir_error(char *str)
{
	printf("no dir find\n");
	exit(1);
}

void readdir_error(char *str)
{
	printf("read_error\n");
	exit(1);
}

void stat_error()
{
	ft_printf("error stat\n");
	exit(1);
}

void error_malloc()
{
	exit(1);
}

// void init_info(t_info *info)
// {
// 	info
// 	info->next = NULL;
// }

void dir_lst(t_dna *dna, char *path)
{
	DIR				*dir;
	t_info			*info;
	t_info			*tmp;
	struct dirent	*ret;
	struct stat		buf;

	if(!(dir = opendir(path)))
		opendir_error("error\n");

	while ((ret = readdir(dir)))
	{
		if(!(info = ft_memalloc(sizeof(t_info))))
			error_malloc();
		if (stat(path, &buf))
			stat_error();
		ft_strcpy(info->name, ret->d_name);
		info->protection = buf.st_mode;


		if (!dna->dir_lst)
			dna->dir_lst = info;
		else
		{
			tmp = dna->dir_lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = info;
		}


	}
}

void init_dna(t_dna *dna)
{
	dna->dir_lst = NULL;

}

void display(t_dna *dna)
{
	t_info	*tmp;

	tmp = dna->dir_lst;

	while (tmp)
	{
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	DIR		*dir;
	struct	dirent *ret;
	struct	stat buf;
	t_dna	dna;

	init_dna(&dna);

	parsing();

	dir_lst(&dna, ".");

	dna.options += REVERSE;


	lst_sort_ascii(&dna);
	display(&dna);

	// ft_printf("FUCK  %-20s fuck\n", "helloopiou");
    //
	// if(!(dir = opendir(".")))
	// 	opendir_error("error\n");

	// printf("%d\n", stat("Makefile", &buf));
	// printf("%d\n", errno);
    //

	// ft_printf("%d\n", buf.st_size);
	// ft_printf("%d\n", buf.st_atime);
	// char *toto = ctime(&buf.st_atime);
    //
	// ft_printf("  %s   \n", toto);
	// ft_printf("%d\n", buf->st_size);


	return(0);
}
