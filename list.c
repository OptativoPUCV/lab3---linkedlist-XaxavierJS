#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  void *data;
  Node *next;
  Node *prev;
};

struct List {
  Node *head;
  Node *tail;
  Node *current;
};

typedef List List;

Node *createNode(void *data) {
  Node *new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

List *createList() {
  List *L = (List *)malloc(sizeof(List));
  L->head = NULL;
  L->tail = NULL;
  L->current = NULL;
  return L;
}

void *firstList(List *list) {
  if (list->head == NULL) {
    return NULL;
  }
  list->current = list->head;
  return list->current->data;
}

void *nextList(List *list) {
  if (list->current == NULL) {
    return NULL;
  }
  if (list->current->next == NULL) {
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;
}

void *lastList(List *list) {
  if (list->tail == NULL) {
    return NULL;
  }
  list->current = list->tail;
  return list->current->data;
}

void *prevList(List *list) {
  if (list->current == NULL) {
    return NULL;
  }
  if (list->current->prev == NULL) {
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List *list, void *data) {
  Node *node = createNode(data);

  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
  }
}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) {
  Node *node = createNode(data);
  node->data = data;
  node->prev = list->current;
  node->next = list->current->next;

  if (list->current->next != NULL) {
    list->current->next->prev = node;
  } else {
    list->tail = node;
  }

  list->current->next = node;
}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) { return NULL; }

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}