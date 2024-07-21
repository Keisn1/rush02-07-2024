/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:21:45 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 22:25:59 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	convert(char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	if (ft_strlen(nbr) == 1)
		return (convert_one_digit_nbr(nbr, spell_nodes, !first));
	if (ft_strlen(nbr) == 2)
		return (convert_two_digit_nbr(nbr, spell_nodes, !first));
	if (ft_strlen(nbr) == 3)
		return (convert_three_digit_nbr(nbr, spell_nodes, !first));
	return (convert_larger_999(nbr, spell_nodes, first));
}

int	convert_cubics(char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	char	*new_nbr2;
	char	*ret;
	int		rest;
	int		size;
	int		i;

	rest = ft_strlen(nbr) % 3;
	rest = ft_strlen(nbr) % 3;
	size = (((ft_strlen(nbr) - 1) / 3) * 3) + 2;
	new_nbr2 = (char *)malloc(sizeof(char) * size);
	new_nbr2[0] = '1';
	i = 1;
	while (i < size)
	{
		new_nbr2[i++] = '0';
	}
	new_nbr2[size - 1] = '\0';
	size = convert_prefix(rest, nbr, spell_nodes, first);
	ret = find_spelled_out(new_nbr2, spell_nodes);
	ft_putstr(" ");
	ft_putstr(ret);
	free(new_nbr2);
	return (size);
}

int	convert_larger_999(char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	int	size;

	size = convert_cubics(nbr, spell_nodes, first);
	nbr += size;
	nbr = skip_zeros(nbr);
	if (*nbr == '\0')
		return (0);
	convert(nbr, spell_nodes, FALSE);
	return (0);
}

int	convert_prefix(int rest, char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	char	*new_nbr;

	if (rest == 1)
	{
		new_nbr = get_ones_place(nbr);
		convert_one_digit_nbr(new_nbr, spell_nodes, !first);
	}
	if (rest == 2)
	{
		new_nbr = get_tens_place(nbr, FALSE);
		convert_two_digit_nbr(new_nbr, spell_nodes, !first);
	}
	if (rest == 0)
	{
		new_nbr = get_hundreds_place(nbr);
		convert_three_digit_nbr(new_nbr, spell_nodes, !first);
		rest = 3;
	}
	free(new_nbr);
	return (rest);
}
