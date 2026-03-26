#ifndef STACK_PRON
#define STACK_PRON

struct element {
    struct node *data;
    struct element *next;
};

void push(struct element **head, struct node *user_data);
void *pop(struct element **head);

#endif