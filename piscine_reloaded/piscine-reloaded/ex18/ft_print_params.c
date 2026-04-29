/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:10:23 by bmartin-          #+#    #+#             */
/*   Updated: 2025/04/10 17:37:48 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char putchar);

int	main(int argc, char *argv[])
{
	int	i;
	int	letter;

	i = 1;
	letter = 0;
	while (i < argc)
	{
		while (argv[i][letter] != '\0')
		{
			ft_putchar(argv[i][letter]);
			letter++;
		}
		letter = 0;
		ft_putchar('\n');
		i++;
	}
	return (0);
}
