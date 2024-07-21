/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:22:02 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 18:42:44 by kfreyer          ###   ########.fr       */
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

t_SpellNode	*create_spell_nodes(char *numerical[], char *spelled_out[],
		int size)
{
	t_SpellNode	*head;
	t_SpellNode	*current;
	int			count;
	t_SpellNode	*new_node;

	head = NULL;
	current = NULL;
	count = 0;
	while (count < size)
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

t_SpellNode	*init_spell_nodes(char ***dict, int size)
{
	return (create_spell_nodes(dict[0], dict[1], size));
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
		free(current->numerical);
		free(current->spelled_out);
		free(current);
		current = next;
	}
	return ;
}
