/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:07:39 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 18:42:48 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	convert(char *nbr, t_SpellNode *spell_nodes, t_bool first);

int my_fun(int rest, char* nbr, t_SpellNode* spell_nodes, t_bool first) {
	char	*new_nbr;
	char	*new_nbr2;
	char* ret;
	int size;

	size = (((ft_strlen(nbr)-1) / 3) * 3) + 2;
	new_nbr2 = (char*)malloc(sizeof(char) * size);
	new_nbr2[0] = '1';
	for (int i = 1; i < size; i++) {
		new_nbr2[i] = '0';
	}
	new_nbr2[size-1] = '\0';

	if (rest == 1) {
		new_nbr = get_ones_place(nbr);
		convert_one_digit_nbr(new_nbr, spell_nodes, !first);
		nbr += rest;
	}
	if (rest == 2) {
		new_nbr = get_tens_place(nbr, FALSE);
		convert_two_digit_nbr(new_nbr, spell_nodes, !first);
		nbr += rest;
	}
	if (rest == 0) {
		new_nbr = get_hundreds_place(nbr);
		convert_three_digit_nbr(new_nbr, spell_nodes, !first);
		nbr +=3;
	}
	free(new_nbr);

	ret = find_spelled_out(new_nbr2, spell_nodes);
	ft_putstr(" ");
	ft_putstr(ret);
	free(new_nbr2);

	convert(nbr, spell_nodes, FALSE);
	return (0);
}

int	convert(char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	int		rest;

	if (ft_strlen(nbr) == 1)
		return (convert_one_digit_nbr(nbr, spell_nodes, !first));
	if (ft_strlen(nbr) == 2)
		return (convert_two_digit_nbr(nbr, spell_nodes, !first));
	if (ft_strlen(nbr) == 3)
		return (convert_three_digit_nbr(nbr, spell_nodes, !first));
	rest = ft_strlen(nbr) % 3;
	return my_fun(rest, nbr, spell_nodes, first);
}

int	main(int argc, char *argv[])
{
	t_SpellNode	*spell_nodes;
	char		*nbr;
	char		***dict;
	int			size;
	char		*numerical[] = {"0", "1", "2", "3", "9", "10", "11", "20", "30",
				"90", "100", "1000", "1000000"};
	char		*spelled_out[] = {"zero", "one", "two", "three", "nine", "ten",
				"eleven", "twenty", "thirty", "ninety", "hundred", "thousand",
				"million"};

	if (!check_args(argc))
	{
		return (EXIT_FAILURE);
	}
	dict = (char ***)malloc(sizeof(char **) * 3);
	size = 13;
	dict[0] = numerical;
	dict[1] = spelled_out;
	spell_nodes = init_spell_nodes(dict, size);
	free(dict);
	ft_putstr(argv[1]);
	ft_putstr(": ");
	if (!check_nbr(argv[1]))
	{
		free_spell_nodes(spell_nodes);
		return (EXIT_FAILURE);
	}
	nbr = get_nbr(argv[1]);
	if (convert(nbr, spell_nodes, TRUE) == -1)
		return (EXIT_FAILURE);
	ft_putstr("\n");
	free(nbr);
	free_spell_nodes(spell_nodes);
	return (EXIT_SUCCESS);
}
