/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:51:14 by bmartin-          #+#    #+#             */
/*   Updated: 2025/12/19 14:51:17 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];
	int		i;
	long	num;

	i = 0;
	num = n;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}
	while (i-- > 0)
		write(fd, &buffer[i], 1);
}
