#include "rush02.h"

void convert(char *nbr) {
    if (str_equal(nbr, "0")) {
        ft_putstr("zero");
    }
    if (str_equal(nbr, "1")) {
        ft_putstr("one");
    }
    if (str_equal(nbr, "2")) {
        ft_putstr("two");
    }
    if (str_equal(nbr, "10")) {
        ft_putstr("ten");
    }
}

int main(int argc, char *argv[]) {
    if (!check_args(argc)) {
        return EXIT_FAILURE;
    }

    ft_putstr(argv[1]);
    ft_putstr(": ");

    if (!check_nbr(argv[1])) {
        return EXIT_FAILURE;
    }

    char *nbr = get_nbr(argv[1]);

    convert(nbr);
    ft_putstr("\n");

    free(nbr);

    return EXIT_SUCCESS;
}
