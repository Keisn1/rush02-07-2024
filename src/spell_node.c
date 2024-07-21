#include "rush02.h"

t_SpellNode* create_node(char* numerical, char* spelled_out) {
        t_SpellNode* newNode = (t_SpellNode*)malloc(sizeof(t_SpellNode));
        if (newNode == NULL) {
            ft_putstr("memory allocation failed");
        }
        newNode->numerical = numerical;
        newNode->spelled_out = spelled_out;
        newNode->next= NULL;
        return newNode;
}

t_SpellNode* init_spell_nodes() {
    char* numerical[] = {"0", "1", "2","3", "10", "11", "20", "100" };
    char* spelled_out[] = {"zero", "one", "two", "three", "ten", "eleven", "twenty", "hundred"};
    t_SpellNode* head = NULL;
    t_SpellNode* current = NULL;
    int count = 0;

    while (count < 8) {
        t_SpellNode* newNode = create_node(numerical[count], spelled_out[count]);
        if (head == NULL) {
            head = newNode;
            current = head;
            count++;
            continue;
        }
        current->next = newNode;
        current = current->next;
        count++;
    }
    return head;
}

void free_spell_nodes(t_SpellNode *head) {
    t_SpellNode* next = head;
    t_SpellNode* current = head;

    while (current != NULL) {
        next = current->next;
        free(current); // Free the current node
        current = next;
    }

    return;
}

char *find_spelled_out(char* nbr, t_SpellNode *spell_nodes) {
    while (spell_nodes != NULL) {
        if (str_equal(nbr, spell_nodes->numerical))
            return spell_nodes->spelled_out;
        spell_nodes = spell_nodes->next;
    }
    return NULL;
}


void print_node(t_SpellNode *sn) {
    ft_putstr("Numerical: ");
    ft_putstr(sn->numerical);
    ft_putstr("\n");
    ft_putstr("Spelled out: ");
    ft_putstr(sn->spelled_out);
    ft_putstr("\n");
}
