/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:02:15 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:02:16 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_bool	check_args(int argc)
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	check_nbr(char *str)
{
	str = skip_space(str);
	if (!is_digit(*str))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (FALSE);
	}
	return (TRUE);
}

int	error(char *type, char *suppl)
{
	if (str_equal(type, "find spelled_out"))
	{
		ft_putstr_err("Error finding");
		ft_putstr_err(suppl);
		ft_putstr_err("\n");
		return (-1);
	}
	return (-1);
}
