/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 22:14:06 by lchety            #+#    #+#             */
/*   Updated: 2018/02/28 01:39:36 by lchety           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *ret;
	struct stat buf;

	// ft_printf("FUCK  %-20s fuck\n", "helloopiou");

	if(!(dir = opendir(".")))
		opendir_error("error\n");

	// int readdir(DIR *dir, struct dirent *entry, struct dirent **result);

	// if(!(ret = readdir(dir)))
	// 	readdir_error("error\n");
	// 	printf("\n%s\n", ret->d_name);
	// if(!(ret = readdir(dir)))
	// 	readdir_error("error\n");
	// 	printf("\n%s\n", ret->d_name);
	// if(!(ret = readdir(dir)))
	// 	readdir_error("error\n");
	// 	printf("\n%s\n", ret->d_name);

	while ((ret = readdir(dir)))
	{
		printf("\n%s\n", ret->d_name);

	}

	// printf("%d\n", stat("Makefile", &buf));
	// printf("%d\n", errno);

	if (stat("./Makefile", &buf))
		stat_error();
	ft_printf("%d\n", buf.st_size);
	ft_printf("%d\n", buf.st_atime);
	char *toto = ctime(&buf.st_atime);

	ft_printf("  %s   \n", toto);
	// ft_printf("%d\n", buf->st_size);



	// printf("%d\n", dir->__dd_fd);
	// printf("\n%c\n", ret->d_type);


	return(0);
}
