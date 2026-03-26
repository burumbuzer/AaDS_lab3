#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(struct element **head, struct node *user_data) {
    struct element *tmp = malloc(sizeof(struct element));
    tmp->data = user_data;
    tmp->next = *head;
    *head = tmp;
}

void *pop(struct element **head) {
    if (*head == NULL) return NULL;
    struct node *ret = (*head)->data;
    struct element *tmp = *head;
    *head = (*head)->next;
    return ret;
}