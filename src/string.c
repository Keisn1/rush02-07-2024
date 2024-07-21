#include "rush02.h"

t_bool is_space(char c) {
    if (c >= '\t' && c <= '\r')
        return TRUE;
    if (c == ' ')
        return TRUE;
    return FALSE;
}

t_bool is_digit(char c) {
    if (c >= '0' && c <= '9')
        return TRUE;
    return FALSE;
}

t_bool str_equal(char *str1, char *str2) {
    if (ft_strcmp(str1, str2)) {
        return FALSE;
    }
    return TRUE;
}


int len_number(char* s) {
    int count = 0;
    while (s[count] && is_digit(s[count])) {
        count++;
    }
    return count;
}

char* skip_space(char *str) {
    while (*str && is_space(*str))
        str++;
    return str;
}

char *get_nbr(char *str) {
    str = skip_space(str);
    char* nbr = (char*)malloc(len_number(str)+1 * sizeof(char));
    if (nbr == NULL) {
        write(STDERR_FILENO, "Error\n", 7);
        return NULL;
    }

    ft_strlcpy(nbr, str, len_number(str)+1);
    return nbr;
}
