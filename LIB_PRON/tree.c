#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

void postfix_print(struct node *p) {
  if (p->l != NULL) postfix_print(p->l);
  if (p->r != NULL) postfix_print(p->r);
  printf("%s ", p->data);
}

void prefix_print(struct node *p) {
  printf("%s ", p->data);
  if (p->l != NULL) prefix_print(p->l);
  if (p->r != NULL) prefix_print(p->r);
}

void symmetry_print(struct node *p) {
  if (p->l != NULL) symmetry_print(p->l);
  printf("%s ", p->data);
  if (p->r != NULL) symmetry_print(p->r);
}

int len(char *c) {
  int ret = 0;
  for (int i = 0; i < STRING_SIZE && c[i] != '\0'; i++) {
    ret++;
  }
  return ret;
}

// Высота (глубина??) дерева
int tree_depth(struct node *p, int len) {
    int l_len = len, r_len = len;
    if (p->l != NULL) l_len = tree_depth(p->l, len+1);
    if (p->r != NULL) r_len = tree_depth(p->r, len+1);
    return MAX(l_len, r_len);
}

// Максимальная длина узла
int max_node(struct node *p) {
  if (p->l == NULL && p->r == NULL) return len(p->data);
  int l_max = 0, r_max = 0;
  if (p->l != NULL) l_max = max_node(p->l);
  if (p->r != NULL) r_max = max_node(p->r);
  return MAX(l_max, r_max);
}

// Рекурсивное заполнение сетки
void fill_grid(struct node *parent, int level, int shift, int start_pos, int ue, char **grid) {
    if (parent == NULL) return;
    if (parent->l != NULL) {
        int pos = start_pos - (start_pos / 2) - 1;
        char buf[ue+1];
        strcpy(buf, parent->l->data);
        char *c = buf;
        for (int i = 0; *c != 0; c++, i++) {
            grid[level][(shift * ue) + (pos * ue) + i] = *c;
        }
        fill_grid(parent->l, level + 1, shift, pos, ue, grid);
    }
    if (parent->r != NULL) {
        int pos = start_pos + (start_pos / 2) + 1;
        char buf[ue+1];
        strcpy(buf, parent->r->data);
        char *c = buf;
        for (int i = 0; *c != 0; c++, i++) {
            grid[level][(shift * ue) + (pos * ue) + i] = *c;
        }
        fill_grid(parent->r, level + 1, shift + start_pos + 1, pos - start_pos - 1, ue, grid);
    }
}

// КРАСИВЫЙ вывод дерева с использованием рекурсивного заполнения сетки
void tree_print(struct node *p) {
    int ue = max_node(p); // У. е. - размер крупнейшего узла дерева
    int height = tree_depth(p, 1);
    int width = (1 << height) - 1; // Ширина дерева в у.е. 2^height - 1

    char **grid = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(ue * width * sizeof(char) + sizeof(char));
        for (int j = 0; j < ue * width; j++) grid[i][j] = ' ';
        grid[i][width * ue] = '\0';
    }

    int start_pos = width / 2;
    char buf[ue+1];
    strcpy(buf, p->data);
    char *c = buf;
    for (int i = 0; *c != 0; c++, i++) {
        grid[0][start_pos * ue + i] = *c;
    }
    fill_grid(p, 1, 0, start_pos, ue, grid);
    for (int i = 0; i < height; i++) printf("%s\n", grid[i]);
}