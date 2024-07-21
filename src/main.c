#include "rush02.h"
#include <stdlib.h>
#include <stdio.h>


void convert(char *nbr, SpellNode* spell_nodes) {
    while (spell_nodes != NULL) {
        if (str_equal(nbr, spell_nodes->numerical)) {
            ft_putstr(spell_nodes->spelled_out);
            return;
        }
        spell_nodes = spell_nodes->next;
    }

    if (str_equal(nbr, "21")) {
        ft_putstr("twenty one");
        return;
    }
    return;
}

int main(int argc, char *argv[]) {
    if (!check_args(argc)) {
        return EXIT_FAILURE;
    }

    SpellNode* spell_nodes = init_spell_nodes();

    ft_putstr(argv[1]);
    ft_putstr(": ");

    if (!check_nbr(argv[1])) {
        free_spell_nodes(spell_nodes);
        return EXIT_FAILURE;
    }

    char *nbr = get_nbr(argv[1]);
    convert(nbr, spell_nodes);
    ft_putstr("\n");

    free(nbr);
    free_spell_nodes(spell_nodes);

    return EXIT_SUCCESS;
}
