/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamahtal <mamahtal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:25:13 by mqwa              #+#    #+#             */
/*   Updated: 2023/11/11 15:57:28 by mamahtal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char	s1[15] = "Bonjour";
	char	s2[15] = "Bonjour";

	printf("ft_isalpha\n%d\n%d\n%d\n",
	ft_isalpha('a') == 1,
	ft_isalpha('A') == 1,
	ft_isalpha('5') == 0);
	printf("ft_isdigit\n%d\n%d\n",
	ft_isdigit('a') == 0,
	ft_isdigit('5') == 1);
	printf("ft_isalnum\n%d\n%d\n%d\n%d\n",
	ft_isalnum('a') == 1,
	ft_isalnum('A') == 1,
	ft_isalnum('5') == 1,
	ft_isalnum('+') == 0);
	printf("ft_isascii\n%d\n%d\n%d\n",
	ft_isascii(10) == 1,
	ft_isascii(127) == 1,
	ft_isascii(128) == 0);
	printf("ft_isprint\n%d\n%d\n%d\n",
	ft_isprint(31) == 0,
	ft_isprint(127) == 0,
	ft_isprint(32) == 1);
	printf("ft_strlen\n%d\n%d\n",
	ft_strlen("Bonjour") == 7,
	ft_strlen("") == 0);
	printf("ft_memset\n%d\n",
	strcmp(ft_memset(s1, 'a', 5), memset(s2, 'a', 5)) == 0);
	ft_bzero(s1, 5);
	bzero(s2, 5);
	printf("ft_bzero\n%d\n",
	strcmp(s1, s2) == 0);
	return (0);
}
