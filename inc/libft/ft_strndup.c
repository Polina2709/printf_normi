/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:45:01 by jczech            #+#    #+#             */
/*   Updated: 2020/02/22 13:45:36 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char *ret;

	ret = malloc(len + 1);
	ft_bzero(ret, len + 1);
	if (!ret)
		return (NULL);
	ft_strncpy(ret, src, len);
	return (ret);
}
