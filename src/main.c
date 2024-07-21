/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:07:39 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 22:07:16 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	t_SpellNode	*spell_nodes;
	int			fd;
	char		buffer[1024];
	char		*nbr;

	if (!check_args(argc))
		return (EXIT_FAILURE);
	fd = 0;
	open_file(&fd, "numbers.dict");
	read_file(&fd, buffer, sizeof(buffer));
	parse_buffer(buffer, &spell_nodes);
	if (!check_nbr(argv[1]))
	{
		free_spell_nodes(spell_nodes);
		close_file(&fd);
		return (EXIT_FAILURE);
	}
	nbr = parse_nbr(argv[1]);
	if (convert(nbr, spell_nodes, TRUE) < 0)
	{
		free(nbr);
		free_spell_nodes(spell_nodes);
		close_file(&fd);
		return (EXIT_FAILURE);
	}
	ft_putstr("\n");
	free(nbr);
	free_spell_nodes(spell_nodes);
	close_file(&fd);
	return (EXIT_SUCCESS);
}
