/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:21:45 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 20:02:47 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	convert_one_digit_nbr(char *nbr, t_SpellNode *spell_nodes,
		t_bool with_whitespace)
{
	char	*ret;

	ret = find_spelled_out(nbr, spell_nodes);
	if (ret == NULL)
		return (error("find spelled_out", nbr));
	if (with_whitespace)
		ft_putstr(" ");
	ft_putstr(ret);
	return (0);
}

int	convert_two_digit_nbr(char *nbr, t_SpellNode *spell_nodes,
		t_bool with_whitespace)
{
	char	*ret;

	if (!pre_check(nbr, spell_nodes, with_whitespace))
		return (0);
	if (with_whitespace)
		ft_putstr(" ");
	write_tens_place(nbr, spell_nodes);
	ft_putstr(" ");
	nbr++;
	ret = find_spelled_out(nbr, spell_nodes);
	if (ret == NULL)
		return (error("find spelled_out", nbr));
	ft_putstr(ret);
	return (0);
}

int	convert_three_digit_nbr(char *nbr, t_SpellNode *spell_nodes,
		t_bool with_whitespace)
{
	char	*ret;

	if (!pre_check_3_digits(nbr, spell_nodes, with_whitespace))
	{
		return (0);
	}
	if (with_whitespace)
		ft_putstr(" ");
	write_ones_place(nbr, spell_nodes);
	ft_putstr(" ");
	ret = find_spelled_out("100", spell_nodes);
	if (ret == NULL)
		return (error("find spelled_out", "100"));
	ft_putstr(ret);
	nbr++;
	return (convert_two_digit_nbr(nbr, spell_nodes, TRUE));
}
