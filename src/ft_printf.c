/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:46:34 by tmyrcell          #+#    #+#             */
/*   Updated: 2020/02/22 13:42:51 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static size_t	recording_process(const char *format, va_list ap, char **ret)
{
	size_t	len;
	size_t	index;
	char	*temp;

	temp = NULL;
	index = 0;
	len = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			*ret = ft_record_ret(*ret, format, len, index);
			len += index;
			format += index + 1;
			index = ft_find_format(&format, &temp, ap);
			*ret = ft_record_ret(*ret, temp, len, index);
			ft_strdel(&temp);
			len += index;
			index = 0;
		}
		else
			index++;
	}
	index = ft_strlen(format);
	*ret = ft_record_ret(*ret, format, len, index);
	len += index;
	return (len);
}

int				ft_printf(const char *format, ...)
{
	char	*ret;
	va_list	ap;
	size_t	len;

	ret = NULL;
	va_start(ap, format);
	len = recording_process(format, ap, &ret);
	write(1, ret, len);
	free(ret);
	va_end(ap);
	return (len);
}

char			*ft_record_ret(char *ret, const char *format, size_t l1,
		size_t l2)
{
	char	*tmp;
	size_t	size;

	size = l1 + l2;
	tmp = ft_strnew(size);
	if (!tmp)
		return (NULL);
	if (ret)
	{
		ft_strncpy(tmp, ret, l1);
		free(ret);
	}
	ft_strncpy(tmp + l1, format, l2);
	return (tmp);
}
