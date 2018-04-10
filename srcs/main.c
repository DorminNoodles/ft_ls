/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:14:06 by lchety            #+#    #+#             */
/*   Updated: 2018/04/10 20:50:26 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_ls.h"

// void init_info(t_info *info)
// {
// 	info
// 	info->next = NULL;
// }

void add_new_link(t_info **info, t_info *new)
{
	t_info *tmp;

	tmp = *info;
	if (!tmp)
	{
		*info = new;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void open_recursive(t_dna *dna, t_info *info_lst, char *path)
{
	char			*new_path;
	struct stat		buf;
	DIR		*dir;

	path = ft_strjoin(path, "/");
	while (info_lst)
	{
		// printf(">>>>> %s          \n", info_lst->name);
		//prendre l ancien path et le nouveau nom pour les join
		if (ft_strcmp(info_lst->name, ".") && ft_strcmp(info_lst->name, ".."))
		{
			// printf(">>>>> %s          \n", info_lst->name);
			new_path = ft_strjoin(path, info_lst->name);

			// printf("new_path %s\n", new_path);
			// if ((dir = opendir(new_path)))
			// {
				// printf("%s    C EST UN DIR\n", new_path);
				// printf("OPEN DIR @@@@\n");
				// dir_lst(dna, new_path);
			// }
			if (stat(new_path, &buf) == -1)
				error("stat");

		 	if ((buf.st_mode & S_IFMT) == S_IFDIR)
			{
				ft_printf("%s\n", new_path);
				dir_lst(dna, new_path);
			}
				// printf("dossier\n");
		}
		info_lst = info_lst->next;
	}
}

void dir_lst(t_dna *dna, char *path)
{
	DIR				*dir;
	t_info			*info_lst;
	t_info			*tmp;
	struct dirent	*ret;
	struct stat		buf;

	info_lst = NULL;

	if(!(dir = opendir(path)))
		error("open_dir_error\n");

	while ((ret = readdir(dir)))
	{
		if (!(tmp = ft_memalloc(sizeof(t_info))))
			error("malloc");
		//save premier maillon
		// if (stat(path, &buf))
		// 	error("stat");

		ft_strcpy(tmp->name, ret->d_name);
		// info->protection = buf.st_mode;

		add_new_link(&info_lst, tmp);
	}
	display_lst_dir(info_lst);

	if (dna->options & RECURSIVE)
	{
		ft_printf("\n");
		open_recursive(dna, info_lst, path);
	}
}


void init_dna(t_dna *dna)
{
	dna->dir_lst = NULL;

}


int main(int argc, char **argv)
{
	DIR		*dir;
	struct	dirent *ret;
	struct	stat buf;
	t_dna	dna;

	init_dna(&dna);
	parsing(&dna, argc, argv);


	if (dna.options & RECURSIVE)
	{


	}

	dir_lst(&dna, ".");

	// lst_sort_ascii(&dna);
	// display(&dna);

	return(0);
}
