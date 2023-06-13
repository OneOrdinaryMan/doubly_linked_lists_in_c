# Doubly Linked Lists in C
In a doubly linked list, the node contains both the next and previous pointers and the value of the node.
The linked list contains the head, the tail and the size of the list. They contain these functions,
- [x] Prepend
- [x] Append
- [x] Remove head
- [x] Remove tail
- [x] Get value
- [x] Get index
- [x] Insert at index
- [x] Remove at index
## Doubly linked list data structure.
The structure of the linked list is,

The main struct contains the head and tail node pointers along with the size of the linked list. The Node struct contains the value contained in the node along with the pointer
to the next node and the prev node.

__Pseudo Code__
```c
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
```
## Prepend
Prepend functions adds the new node as head and changing the current head as next of the new node. If there is no nodes in the list, the new node is both head and tail of the list.

__Pseudo Code__
```c
void prepend(linked_list *input_list, int value) {
  node *new_node = create_node(value);

  if (input_list->size == 0) {
    input_list->head = new_node;
    input_list->tail = new_node;
    input_list->size++;
    return;
  }

  node *current_head = input_list->head;
  new_node->next = current_head;
  input_list->head = new_node;
  input_list->size++;
}
```
## Append
Append function adds the new node at the tail and update the tail of the list to new node.The previous tail is the previous of the current tail and the next of the previous tail
is the new tail.If there is no nodes in the list, the new node is both the head and tail of the list.

__Pseudo Code__
```c
void append(linked_list *input_list, int value) {
  node *new_node = create_node(value);

  if (input_list->size == 0) {
    input_list->head = new_node;
    input_list->tail = new_node;
    input_list->size++;
    return;
  }

  node *current_tail = input_list->tail;
  input_list->tail = new_node;
  current_tail->next = new_node;
  new_node->prev = current_tail;
  input_list->size++;
}
```
## Remove head
Remove head will remove the head node and the struct will have the next node as the head. Returns if list is empty.

__Pseudo Code__
```c
int remove_head(linked_list *input_list) {
  if (input_list->size == 0) {
    printf("The list is empty.\n");
    return 0;
  }

  node *current_head = input_list->head;
  int return_value = current_head->value;
  input_list->head = current_head->next;
  free(current_head);
  if (input_list->head != NULL) {
    input_list->head->prev = NULL;
  }
  input_list->size--;
  return return_value;
}
```
## Remove tail
Removes the tail and the struct will have the previous of the current tail as the tail. Returns if the list is empty.

__Pseudo Code__
```c
int remove_tail(linked_list *input_list) {
  if (input_list->size == 0) {
    printf("The list is empty\n");
    return 0;
  }
  node *current_tail = input_list->tail;
  input_list->tail = current_tail->prev;
  input_list->tail->next = NULL;
  int return_value = current_tail->value;
  free(current_tail);
  input_list->size--;
  return return_value;
}
```
## Get value
Get value function will get the value of the node at a specific index. If the index is greater than or equal to the size it will return 0.

__Pseudo Code__
```c
int get_value(linked_list *input_list, int index) {
  if (index >= input_list->size) {
    printf("The list is empty.\n");
    return 0;
  }

  int i = 0;
  node *current_node = input_list->head;

  for (; i < index; i++) {
    current_node = current_node->next;
  }

  return current_node->value;
}
```
## Get index
The index functions takes in a value and compare the value in the list and when a node matches the list it returns the index.

__Pseudo Code__
```c
int get_index(linked_list *input_list, int value) {
  if (input_list->size == 0) {
    printf("The list is empty.\n");
    return -1;
  }

  int i = 0;
  node *current_node = input_list->head;

  for (; i < input_list->size; i++) {
    if (current_node->value == value) {
      return i;
    }

    current_node = current_node->next;
  }

  return -1;
}
```
## Insert at index
Insert at index will just insert the new node at the specified index. If index is greater than the size, it will return with __Index out of bounds__ error. If index is 0, it will
prepend to the list. If index is the size, it will just append.

__Pseudo Code__
```c
void insert_at_index(linked_list *input_list, int index, int value) {
  if (index > input_list->size) {
    printf("Index out of bounds!\n");
    return;
  } else if (index == 0) {
    prepend(input_list, value);
    return;
  } else if (index == input_list->size) {
    append(input_list, value);
    return;
  }
  node *current_node = input_list->head;
  int i = 0;
  for (; i < index; i++) {
    current_node = current_node->next;
  }
  node *new_node = create_node(value);
  node *prev_node = current_node->prev;
  prev_node->next = new_node;
  new_node->prev = prev_node;
  new_node->next = current_node;
  current_node->prev = new_node;
  input_list->size++;
}
```
## Remove at index
Remove the node at index and free the pointer. Returns the value of the freeing node. If index is greater than size, returns with 0. If index is 0, uses remove head function.
If the index is the size - 1, uses remove tail.

__Pseudo Code__
```c
int remove_at_index(linked_list *input_list, int index) {
  if (index >= input_list->size) {
    printf("Index out of bounds!\n");
    return 0;
  } else if (index == 0) {
    return remove_head(input_list);
  } else if (index == input_list->size - 1) {
    return remove_tail(input_list);
  }

  node *current_node = input_list->head;
  int i = 0;
  for (; i < index; i++) {
    current_node = current_node->next;
  }
  node *prev_node = current_node->prev;
  node *next_node = current_node->next;
  prev_node->next = next_node;
  next_node->prev = prev_node;
  int return_value = current_node->value;
  free(current_node);
  input_list->size--;
  return return_value;
}
```
# Licence
This project is licenced under <mark>GPL3.0 or later</mark>.Feel free to use the projext.
