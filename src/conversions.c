/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:21:45 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:21:46 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"


int	pre_check_3_digits(char *nbr, t_SpellNode *spell_nodes, t_bool with_whitespace )
{
	if (str_equal(nbr, "000"))
		return (0);
	if (*nbr == '0') {
		return (convert_two_digit_nbr(++nbr, spell_nodes, with_whitespace));
	}
	return (1);
}

int	pre_check(char *nbr, t_SpellNode *spell_nodes, t_bool with_whitespace)
{
	char	*ret;

	if (str_equal(nbr, "00"))
		return (0);
	if (*nbr == '0') {
		return (convert_one_digit_nbr(++nbr, spell_nodes, TRUE));
	}
	ret = find_spelled_out(nbr, spell_nodes);
	if (ret != NULL)
		{
			if (with_whitespace)
				ft_putstr(" ");
			ft_putstr(ret);
			return (0);
		}
	return (1);
}

int write_ones_place(char *nbr, t_SpellNode *spell_nodes) {
	char* ones_place = get_ones_place(nbr);
	if (ones_place == NULL)
		return (-1);
	char* ret = find_spelled_out(ones_place, spell_nodes);
	if (ret == NULL)
		return (error("find spelled_out", ones_place));
	ft_putstr(ret);
    free(ones_place);
    return 0;
}

int write_tens_place(char *nbr, t_SpellNode *spell_nodes) {
	char* tens_place = get_tens_place(nbr, TRUE);
	if (tens_place == NULL)
		return (error("memory allocation", "tens_place"));
	char* ret = find_spelled_out(tens_place, spell_nodes);
	if (ret == NULL)
		return (error("find spelled_out", tens_place));
	ft_putstr(ret);
	free(tens_place);
    return 0;
}

int	convert_one_digit_nbr(char *nbr, t_SpellNode *spell_nodes, t_bool with_whitespace)
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


int	convert_two_digit_nbr(char *nbr, t_SpellNode *spell_nodes, t_bool with_whitespace)
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


int	convert_three_digit_nbr(char *nbr, t_SpellNode *spell_nodes, t_bool with_whitespace)
{
	char	*ret;

    if (!pre_check_3_digits(nbr, spell_nodes, with_whitespace)) {
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
