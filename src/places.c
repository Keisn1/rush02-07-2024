#include "rush02.h"

char *get_tens_place(char *nbr) {
    char* tens_place = (char*)malloc((2 + 1) * sizeof(char));
    if (tens_place == NULL) {
        ft_putstr("Error");
        return NULL;
    }
    tens_place[0] = nbr[0];
    tens_place[1] = '0';
    tens_place[2] = '\0';
    return tens_place;
}

char *get_ones_place(char *nbr) {
    char* ones_place = (char*)malloc((1 + 1) * sizeof(char));
    if (ones_place == NULL) {
        ft_putstr("Error");
        return NULL;
    }
    ones_place[0] = nbr[0];
    ones_place[1] = '\0';
    return ones_place;
}

int convert_one_digit_nbr(char *nbr, t_SpellNode* spell_nodes) {
    char* ret = find_spelled_out(nbr, spell_nodes);
    if (ret == NULL) 
        return error("find spelled_out", nbr);
    ft_putstr(ret);
    return 0;
}

int convert_two_digit_nbr(char *nbr, t_SpellNode* spell_nodes) {
        if (str_equal(nbr, "00"))
            return 0;

        if (*nbr == '0')
            return convert_one_digit_nbr(++nbr, spell_nodes);

        char* ret = find_spelled_out(nbr, spell_nodes);
        if (ret != NULL) {
            ft_putstr(ret);
            return 0;
        }

        char *tens_place = get_tens_place(nbr);
        if (tens_place == NULL)
            return -1;

        ret = find_spelled_out(tens_place, spell_nodes);
        if (ret == NULL) 
            return error("find spelled_out", tens_place);
        ft_putstr(ret);
        free(tens_place);

        ft_putstr(" ");

        nbr++;
        ret = find_spelled_out(nbr, spell_nodes);
        if (ret == NULL) 
            return error("find spelled_out", nbr);
        ft_putstr(ret);
        return 0;
}

int convert_three_digit_nbr(char *nbr, t_SpellNode* spell_nodes) {
        char *ones_place = get_ones_place(nbr);
        if (ones_place == NULL)
            return -1;

        char* ret = find_spelled_out(ones_place, spell_nodes);
        if (ret == NULL)  
            return error("find spelled_out", ones_place);
        
        ft_putstr(ret);
        free(ones_place);

        ft_putstr(" ");
        ret = find_spelled_out("100", spell_nodes);
        if (ret == NULL) 
            return error("find spelled_out", "100");
        ft_putstr(ret);

        ft_putstr(" ");
        nbr++;
        return convert_two_digit_nbr(nbr, spell_nodes);
}
