/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:51:14 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/11 11:26:40 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	m;

	m = 1;
	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			m = -m;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr)
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (m * res);
}
