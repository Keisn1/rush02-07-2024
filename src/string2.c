/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:31:12 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 22:06:53 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*parse_nbr(char *str)
{
	char	*nbr;

	str = skip_space(str);
	nbr = (char *)malloc(len_number(str) + 1 * sizeof(char));
	if (nbr == NULL)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (NULL);
	}
	ft_strlcpy(nbr, str, len_number(str) + 1);
	return (nbr);
}

char	*skip_space(char *str)
{
	while (*str && is_space(*str))
		str++;
	return (str);
}

char	*skip_digits(char *str)
{
	while (*str && is_digit(*str))
		str++;
	return (str);
}

char	*skip_zeros(char *str)
{
	while (*str == '0')
	{
		str++;
	}
	return (str);
}
