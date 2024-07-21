/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:07:39 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 20:05:36 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	convert(char *nbr, t_SpellNode *spell_nodes, t_bool first);

int convert_prefix(int rest, char *nbr, t_SpellNode *spell_nodes, t_bool first) {
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
	return rest;
}

t_bool is_zero(char *str) {
	while (*str) {
		if (*str++ != '0') {
			return FALSE;
		}
	}
	return TRUE;
}

int	convert_bigger(char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	char	*new_nbr2;
	char	*ret;
	int		size;
	int i;

	int rest = ft_strlen(nbr) % 3;

	size = (((ft_strlen(nbr) - 1) / 3) * 3) + 2;
	new_nbr2 = (char *)malloc(sizeof(char) * size);
	new_nbr2[0] = '1';
	i = 1;
	while (i < size) {
		new_nbr2[i++] = '0';
	}
	new_nbr2[size - 1] = '\0';

	nbr += convert_prefix(rest, nbr, spell_nodes, first);

	ret = find_spelled_out(new_nbr2, spell_nodes);
	ft_putstr(" ");
	ft_putstr(ret);
	free(new_nbr2);
	while (*nbr == '0') {
		nbr++;
	}
	if (*nbr == '\0') {
		return 0;
	}
	convert(nbr, spell_nodes, FALSE);
	return (0);
}


int	convert(char *nbr, t_SpellNode *spell_nodes, t_bool first)
{
	if (ft_strlen(nbr) == 1)
		return (convert_one_digit_nbr(nbr, spell_nodes, !first));
	if (ft_strlen(nbr) == 2)
		return (convert_two_digit_nbr(nbr, spell_nodes, !first));
	if (ft_strlen(nbr) == 3)
		return (convert_three_digit_nbr(nbr, spell_nodes, !first));

	return (convert_bigger(nbr, spell_nodes, first));
}

int	main(int argc, char** argv)
{

	if (!check_args(argc))
		return (EXIT_FAILURE);

	t_SpellNode	*spell_nodes;

	int fd;
	char buffer[1024];
	char		*nbr;

	fd = 0;
	open_file(&fd, "numbers.dict");
	read_file(&fd, buffer, sizeof(buffer));
	parse_buffer(buffer, &spell_nodes);

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

	close_file(&fd);
	return (EXIT_SUCCESS);
}
