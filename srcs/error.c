/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 21:13:12 by lchety            #+#    #+#             */
/*   Updated: 2018/04/13 15:55:22 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
// void opendir_error(char *str)
// {
// 	printf("no dir find\n");
// 	exit(1);
// }
//
// void readdir_error(char *str)
// {
// 	printf("read_error\n");
// 	exit(1);
// }
//
// void stat_error()
// {
// 	ft_printf("error stat\n");
// 	exit(1);
// }
//
// void error_malloc()
// {
// 	exit(1);
// }


void error(char *str)
{
	ft_putstr(str);
	exit(1);
}
