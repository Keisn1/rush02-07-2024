/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   places.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:07:59 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:21:38 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_tens_place(char *nbr)
{
	char	*tens_place;

	tens_place = (char *)malloc((2 + 1) * sizeof(char));
	if (tens_place == NULL)
	{
		ft_putstr("Error");
		return (NULL);
	}
	tens_place[0] = nbr[0];
	tens_place[1] = '0';
	tens_place[2] = '\0';
	return (tens_place);
}

char	*get_ones_place(char *nbr)
{
	char	*ones_place;

	ones_place = (char *)malloc((1 + 1) * sizeof(char));
	if (ones_place == NULL)
	{
		ft_putstr("Error");
		return (NULL);
	}
	ones_place[0] = nbr[0];
	ones_place[1] = '\0';
	return (ones_place);
}
