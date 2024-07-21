/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:31:12 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:31:13 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_nbr(char *str)
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
