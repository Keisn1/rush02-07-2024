#ifndef RUSH02_H
#define RUSH02_H

/* libraries */
#include <unistd.h>
#include <stdlib.h>

/* Makro Symbols */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

/* type definitions */
typedef enum BOOL_ {
  FALSE = 0,
  TRUE,
} t_bool;

/* prototypes */

/* errors.c */
t_bool check_args(int argc);
t_bool check_nbr(char *str);
char *get_nbr(char *str);
int error(char *msg, char *suppl);

/* string.c */
char* skip_space(char *str);
int len_number(char* s);
t_bool is_space(char c);
t_bool str_equal(char *str1, char *str2);
t_bool is_digit(char c);

/* libft */
void ft_putstr(char *str);
void ft_putchar(char c);
int	ft_strcmp(char *s1, char *s2);
int ft_strlen(char *s);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void	ft_putnbr(int nb);
void ft_putchar_err(char c);
void ft_putstr_err(char *str);

/* spell_node */
typedef struct spell_node {
    char* numerical;
    char* spelled_out;
    struct spell_node* next;
} SpellNode;

SpellNode* create_node(char* numerical, char* spelled_out);
SpellNode* init_spell_nodes();
void free_spell_nodes(SpellNode *head);
void print_node(SpellNode *sn);
char *find_spelled_out(char* nbr, SpellNode *spell_nodes);

/* places.c */
char *get_tens_place(char *nbr);
char *get_ones_place(char *nbr);
int convert_one_digit_nbr(char *nbr, SpellNode* spell_nodes);
int convert_two_digit_nbr(char *nbr, SpellNode* spell_nodes);
int convert_three_digit_nbr(char *nbr, SpellNode* spell_nodes);
#endif // RUSH02_H
