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

/* spell_node */
typedef struct spell_node {
    char* numerical;
    char* spelled_out;
    struct spell_node* next;
} SpellNode;

SpellNode* create_node(char* numerical, char* spelled_out);
void free_spell_nodes(SpellNode *head);
SpellNode* init_spell_nodes();
void print_node(SpellNode *sn);
#endif // RUSH02_H
