#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
};
typedef struct Node node;
typedef struct {
  int size;
  node *head;
  node *tail;
} linked_list;
linked_list create_list();
node *create_node(int);
void prepend(linked_list *, int);
void append(linked_list *, int);
int get_index(linked_list *, int);
int get_value(linked_list *, int);
int remove_head(linked_list *);
int remove_tail(linked_list *);
void insert_at_index(linked_list *, int, int);
int remove_at_index(linked_list *, int);
void delete_list(linked_list *);
#endif
