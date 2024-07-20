#include "rush02.h"
#include <stdlib.h>

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



    char* arg1 = argv[1];
    arg1 = skip_space(arg1);

    if (*arg1 == '-') {
        ft_putstr(argv[1]);
        ft_putstr(": ");
        write(STDERR_FILENO, "Error\n", 7);
        return EXIT_FAILURE;
    }
    char* nbr = (char*)malloc(len_number(arg1)+1 * sizeof(char));
    if (nbr == NULL) {
        write(STDERR_FILENO, "Error\n", 7);
        return EXIT_FAILURE;
    }
    ft_strlcpy(nbr, arg1, len_number(arg1)+1);

    ft_putstr(nbr);
    ft_putstr(": ");
    convert(nbr);
    ft_putstr("\n");

    free(nbr);

    return EXIT_SUCCESS;
}
