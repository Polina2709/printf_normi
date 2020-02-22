/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:51:13 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 11:51:55 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_ldtoa(long double f)
{
	char	*s;

	if (f == 0)
		return (ft_strdup("0"));
	s = non_dec_char(f);
	if (is_dec(f) == 1)
	{
		s = ft_strjoin(s, ".");
		s = ft_strjoin(s, dec_char(f));
		if ((get_dec(f) > 0 && get_dec(f) < 0.1) ||
				(get_dec_neg(f) > 0 && get_dec_neg(f) < 0.1))
			correct_back_ad01(s);
	}
	if (f < 0)
		s = ft_strjoin("-", s);
	return (s);
}
