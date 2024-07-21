#include "rush02.h"
#include <stdlib.h>
#include <stdio.h>

int convert(char *nbr, SpellNode* spell_nodes) {

    if (ft_strlen(nbr) == 1)
        return convert_one_digit_nbr(nbr, spell_nodes);
    /* char* ret = find_spelled_out(nbr, spell_nodes); */
    /* if (ret != NULL) { */
    /*     ft_putstr(ret); */
    /*     return 0; */
    /* } */

    if (ft_strlen(nbr) == 2)
        return convert_two_digit_nbr(nbr, spell_nodes);

    if (ft_strlen(nbr) == 3)
        return convert_three_digit_nbr(nbr, spell_nodes);

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
