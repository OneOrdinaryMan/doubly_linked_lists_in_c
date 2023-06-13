/*
    Doubly Linked Lists in C
    Copyright (C) 2023  Srivathsan Sudarsanan

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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
