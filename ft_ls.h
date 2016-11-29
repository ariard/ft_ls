/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:39:51 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 17:27:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./Libft/includes/libft.h"

typedef struct		s_option
{
	char	mode;
	char	R;
	char	a;
	char	r;
	char	sort;
	char 	G;
	char	g;
	char	e;
	char	aro;
	char	p;
	char	h;
	char	o;
	char	T;
	char	n;
	char	F;
	char	i;
}					t_option;	

t_option			*ft_parse_option(char **argv);

#endif
