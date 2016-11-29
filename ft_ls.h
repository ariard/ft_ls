/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:39:51 by ariard            #+#    #+#             */
/*   Updated: 2016/11/29 14:48:38 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "./Libft/includes/libft.h"

typedef struct		s_option
{
	char	l;
	char	R;
	char	a;
	char	t;
	char	r;
	char 	G;
	char	u;
	char	f;
	char	g;
	char	e;
	char	aro;
	char	S;
	char	p;
	char	m;
	char	h;
	char	o;
	char	T;
	char	U;
	char	uno;
	char	n;
	char	F;
	char	i;
}					t_option;	

t_option			*ft_parse_option(char **argv);

#endif
