#include "lib/lib.h"
#include <stdio.h>
int main() {
  linked_list input = create_list();
  for (int i = 0; i < 10; i++) {
    append(&input, i);
  }
  for (int i = 0; i < 10; i++) {
    printf("%d\t", get_value(&input, i));
  }
  printf("\n");
  remove_tail(&input);
  for (int i = 0; i < 9; i++) {
    printf("%d\t", get_value(&input, i));
  }
  printf("\n");
  delete_list(&input);
  return 0;
}
