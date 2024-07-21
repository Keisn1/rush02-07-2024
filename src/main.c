/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:07:39 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:07:40 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>
#include <stdlib.h>

int	convert(char *nbr, t_SpellNode *spell_nodes)
{
	if (ft_strlen(nbr) == 1)
		return (convert_one_digit_nbr(nbr, spell_nodes));
	if (ft_strlen(nbr) == 2)
		return (convert_two_digit_nbr(nbr, spell_nodes));
	if (ft_strlen(nbr) == 3)
		return (convert_three_digit_nbr(nbr, spell_nodes));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_SpellNode	*spell_nodes;
	char		*nbr;
    char*** dict;

	if (!check_args(argc))
	{
		return (EXIT_FAILURE);
	}

	dict = (char***)malloc(sizeof(char**) * 3);
    int size = 9;
	char	*numerical[] = {"0", "1", "2", "3", "10", "11", "20", "100",
			"1000"};
	char	*spelled_out[] = {"zero", "one", "two", "three", "ten", "eleven",
			"twenty", "hundred", "thousand"};
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
	if (convert(nbr, spell_nodes) == -1)
		return (EXIT_FAILURE);
	ft_putstr("\n");
	free(nbr);
	free_spell_nodes(spell_nodes);
	return (EXIT_SUCCESS);
}
