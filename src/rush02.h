/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <kfreyer@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:02:39 by kfreyer           #+#    #+#             */
/*   Updated: 2024/07/21 21:52:28 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

/* libraries */
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* Makro Symbols */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

/* type definitions */
typedef enum BOOL_
{
	FALSE = 0,
	TRUE,
}						t_bool;

/* ------------------------   prototypes  ---------------------------*/
/* errors.c */
t_bool					check_args(int argc);
t_bool					check_nbr(char *str);
char					*get_nbr(char *str);
int						error(char *msg, char *suppl);

/* string.c */
char					*skip_space(char *str);
char					*skip_digits(char *str);
int						len_number(char *s);
t_bool					is_space(char c);
t_bool					str_equal(char *str1, char *str2);
t_bool					is_digit(char c);

/* libft */
void					ft_putstr(char *str);
void					ft_putchar(char c);
int						ft_strcmp(char *s1, char *s2);
int						ft_strlen(char *s);
unsigned int			ft_strlcpy(char *dest, char *src, unsigned int size);
void					ft_putnbr(int nb);
void					ft_putchar_err(char c);
void					ft_putstr_err(char *str);
char					*ft_strchr(char *str, int c);
char					*ft_strdup(char *src);

/* spell_node */
typedef struct spell_node
{
	char				*numerical;
	char				*spelled_out;
	struct spell_node	*next;
}						t_SpellNode;

t_SpellNode				*create_node(char *numerical, char *spelled_out);
t_SpellNode				*init_spell_nodes(char ***dict, int size);
void					free_spell_nodes(t_SpellNode *head);
void					print_node(t_SpellNode *sn);
char					*find_spelled_out(char *nbr, t_SpellNode *spell_nodes);
char					***get_dict(void);

/* places.c */
char					*get_tens_place(char *nbr, t_bool fill_with_zeros);
char					*get_ones_place(char *nbr);
char					*get_hundreds_place(char *nbr);

/* conversions.c */
int						write_ones_place(char *nbr, t_SpellNode *spell_nodes);
int						convert_one_digit_nbr(char *nbr,
							t_SpellNode *spell_nodes, t_bool with_whitespace);
int						convert_two_digit_nbr(char *nbr,
							t_SpellNode *spell_nodes, t_bool with_whitespace);
int						convert_three_digit_nbr(char *nbr,
							t_SpellNode *spell_nodes, t_bool with_whitespace);
int						pre_check_3_digits(char *nbr, t_SpellNode *spell_nodes,
							t_bool with_whitespace);
int						pre_check(char *nbr, t_SpellNode *spell_nodes,
							t_bool with_whitespace);
int						write_ones_place(char *nbr, t_SpellNode *spell_nodes);
int						write_tens_place(char *nbr, t_SpellNode *spell_nodes);

/* nick.c */
void					parse_buffer(char *buffer, t_SpellNode **head);
int						open_file(int *fd, char *filename);
int						close_file(int *fd);
int						read_file(int *fd, char *buffer, int buffer_size);

#endif // RUSH02_H
