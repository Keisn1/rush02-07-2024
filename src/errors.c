#include "rush02.h"

t_bool check_args(int argc) {
    if (argc != 2) {
        write(STDERR_FILENO, "Error\n", 7);
        return FALSE;
    }
    return TRUE;
}
