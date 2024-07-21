#include "rush02.h"

SpellNode* create_node(char* numerical, char* spelled_out) {
        SpellNode* newNode = (SpellNode*)malloc(sizeof(SpellNode));
        if (newNode == NULL) {
            ft_putstr("memory allocation failed");
        }
        newNode->numerical = numerical;
        newNode->spelled_out = spelled_out;
        newNode->next= NULL;
        return newNode;
}

SpellNode* init_spell_nodes() {
    char* numerical[] = {"0", "1", "2", "10", "11", "20" };
    char* spelled_out[] = {"zero", "one", "two", "ten", "eleven", "twenty"};
    SpellNode* head = NULL;
    SpellNode* current = NULL;
    int count = 0;

    while (count < 6) {
        SpellNode* newNode = create_node(numerical[count], spelled_out[count]);
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

void free_spell_nodes(SpellNode *head) {
    SpellNode* next = head;
    SpellNode* current = head;

    while (current != NULL) {
        next = current->next;
        free(current); // Free the current node
        current = next;
    }

    return;
}

char *find_spelled_out(char* nbr, SpellNode *spell_nodes) {
    while (spell_nodes != NULL) {
        if (str_equal(nbr, spell_nodes->numerical))
            return spell_nodes->spelled_out;
        spell_nodes = spell_nodes->next;
    }
    return NULL;
}


void print_node(SpellNode *sn) {
    ft_putstr("Numerical: ");
    ft_putstr(sn->numerical);
    ft_putstr("\n");
    ft_putstr("Spelled out: ");
    ft_putstr(sn->spelled_out);
    ft_putstr("\n");
}
