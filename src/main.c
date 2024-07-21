#include "rush02.h"
#include <stdlib.h>
#include <stdio.h>

int convert(char *nbr, SpellNode* spell_nodes) {
    char* ret = find_spelled_out(nbr, spell_nodes);
    if (ret != NULL) {
        ft_putstr(ret);
        return 0;
    }

    if (ft_strlen(nbr) == 2) {
        char *tens_place = get_tens_place(nbr);
        if (tens_place == NULL)
            return -1;

        ret = find_spelled_out(tens_place, spell_nodes);
        if (ret != NULL) {
            ft_putstr(ret);
        }
        free(tens_place);

        ft_putstr(" ");

        nbr++;
        ret = find_spelled_out(nbr, spell_nodes);
        if (ret != NULL) {
            ft_putstr(ret);
        }
    }

    return 0;
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
    if (convert(nbr, spell_nodes) == -1)
        return EXIT_FAILURE;
    ft_putstr("\n");

    free(nbr);
    free_spell_nodes(spell_nodes);

    return EXIT_SUCCESS;
}
