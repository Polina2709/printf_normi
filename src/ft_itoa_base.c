/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:48:18 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/21 11:49:51 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	str_len(unsigned long long int n, int base)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		convert_letter(int a)
{
	if (a == 10)
		return ('a');
	if (a == 11)
		return ('b');
	if (a == 12)
		return ('c');
	if (a == 13)
		return ('d');
	if (a == 14)
		return ('e');
	if (a == 15)
		return ('f');
	return (a + '0');
}

char		*ft_itoa_base(unsigned long long int n, int base)
{
	char				*ret;
	int					i;

	if (n == -0)
		return (ft_strdup("0"));
	if (!(ret = ft_strnew(str_len(n, base))))
		return (NULL);
	i = str_len(n, base);
	ret[i--] = 0;
	while (n > 0)
	{
		ret[i] = convert_letter(n % base);
		n = n / base;
		i--;
	}
	return (ret);
}
