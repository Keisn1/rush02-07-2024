/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:22:02 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 15:30:18 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_SpellNode	*create_node(char *numerical, char *spelled_out)
{
	t_SpellNode	*new_node;

	new_node = (t_SpellNode *)malloc(sizeof(t_SpellNode));
	if (new_node == NULL)
	{
		ft_putstr("memory allocation failed");
	}
	new_node->numerical = numerical;
	new_node->spelled_out = spelled_out;
	new_node->next = NULL;
	return (new_node);
}

t_SpellNode	*init_spell_nodes(void)
{
	char		*numerical[] = {"0", "1", "2", "3", "10", "11", "20", "100", "1000"};
	char		*spelled_out[] = {"zero", "one", "two", "three", "ten", "eleven", "twenty", "hundred", "thousand"};
	t_SpellNode	*head;
	t_SpellNode	*current;
	int			count;
	t_SpellNode	*new_node;

	head = NULL;
	current = NULL;
	count = 0;
	while (count < 8)
	{
		new_node = create_node(numerical[count], spelled_out[count]);
		if (head == NULL)
		{
			head = new_node;
			current = head;
			count++;
			continue ;
		}
		current->next = new_node;
		current = current->next;
		count++;
	}
	return (head);
}

void	free_spell_nodes(t_SpellNode *head)
{
	t_SpellNode	*next;
	t_SpellNode	*current;

	next = head;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return ;
}

char	*find_spelled_out(char *nbr, t_SpellNode *spell_nodes)
{
	while (spell_nodes != NULL)
	{
		if (str_equal(nbr, spell_nodes->numerical))
			return (spell_nodes->spelled_out);
		spell_nodes = spell_nodes->next;
	}
	return (NULL);
}

void	print_node(t_SpellNode *sn)
{
	ft_putstr("Numerical: ");
	ft_putstr(sn->numerical);
	ft_putstr("\n");
	ft_putstr("Spelled out: ");
	ft_putstr(sn->spelled_out);
	ft_putstr("\n");
}
