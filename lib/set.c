#include "set.h"

Set init_set() {
  Set set = {
      .arr = NULL,
      .size = 0,
      .capacity = 0,
      .last_elem_index = -1,
  };

  return set;
}

void delete_set(Set *set) {
  if (set->arr == NULL)
    return;
  for (int i = 0; i < set->size; i++)
    free(set->arr[i]);
  free(set->arr);
}

int exists(Set *set, char *elem) {
  for (unsigned int i = 0; i < set->size; i++) {
    if (!strcmp(elem, set->arr[i])) {
      // string already exists
      return 1;
    }
  }

  return 0;
}

void add(Set *set, char *elem) {
  if (set->arr == NULL) {
    set->arr = malloc(sizeof(char *));
    set->capacity = 1;
  }
  if (exists(set, elem)) {
    return;
  }
  if (set->size >= set->capacity) {
    set->capacity = set->capacity * 2;
    set->arr = realloc(set->arr, sizeof(char *) * set->capacity);
  }
  // add element
  set->size++;
  set->last_elem_index++;
  set->arr[set->last_elem_index] = elem;
}

void print_set(Set *set) {
  for (unsigned int i = 0; i < set->size; i++) {
    printf("%s ", set->arr[i]);
  }
}

char **to_array(Set *set) {
  int len = set->size;
  char **arr = malloc(len * sizeof(char *) + 8); // 8 extra bytes for NULL
  // copy pointers
  for (int i = 0; i < len; i++)
    arr[i] = set->arr[i];

  arr[len] = NULL;
  return arr;
}
