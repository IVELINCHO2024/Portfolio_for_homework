#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList init() {
  LinkedList list = {
    .head = NULL,
    .size = 0
  };

  return list;
}

struct Node * createNode(ListType value) {
  struct Node * newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Error allocating memory \n");
    exit(1);
  }
  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

void pushFront(LinkedList * list, ListType value) {
  struct Node * newNode = createNode(value);
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

struct Node * getNode(LinkedList * list, uint index) {

  struct Node * currentNode = list->head;
  for (int i = 0; i < index; i++) {
    currentNode = currentNode->next;
  }

  return currentNode;
}

ListType get(LinkedList * list, uint index) {
  struct Node * currentNode = getNode(list, index);
  return currentNode->value;
}

void push(LinkedList * list, uint index, ListType value) {
  if (index > list->size) {
    printf("Index out of bounds \n");
    exit(1);
  }

  if (index == 0) {
    pushFront(list, value);
  } else {
    struct Node * newNode = createNode(value);
    struct Node * prevNode = getNode(list, index-1);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    list->size++;
  }
 
}

void pushBack(LinkedList * list, ListType value){
    struct Node * newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node * lastNode = getNode(list, list->size - 1);
        lastNode->next = newNode;
    }
    list->size++;
    }

ListType popFront(LinkedList * list) {
  if (list->head == NULL) {
    printf("Cannot popFront from empty list\n");
    exit(1);
  }

  struct Node * nodeToDelete = list->head;
  list->head = nodeToDelete->next;
  
  ListType result = nodeToDelete->value;
  free(nodeToDelete);
  list->size--;

  return result;
}

ListType pop(LinkedList * list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds \n");
        exit(1);
    }
    
    if (index == 0) {
        return popFront(list);
    } else {
        struct Node * prevNode = getNode(list, index-1);
        struct Node * nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
    
        ListType result = nodeToDelete->value;
        free(nodeToDelete);
        list->size--;
    
        return result;
    }
}

ListType popBack(LinkedList * list) {
    if (list->head == NULL) {
        printf("Cannot popBack from empty list\n");
        exit(1);
    }
    
    if (list->size == 1) {
        return popFront(list);
    }
    
    struct Node * prevNode = getNode(list, list->size - 2);
    struct Node * nodeToDelete = prevNode->next;
    prevNode->next = NULL;
    
    ListType result = nodeToDelete->value;
    free(nodeToDelete);
    list->size--;
    
    return result;
}

void set(LinkedList * list, uint index, ListType value) {
    if (index >= list->size) {
        printf("Index out of bounds \n");
        exit(1);
    }
    
    struct Node * currentNode = getNode(list, index);
    currentNode->value = value;
}

void release(LinkedList *list) {
    struct Node * currentNode = list->head;
    while (currentNode != NULL) {
        free(currentNode);
        currentNode = currentNode->next;
    }
    list->head = NULL;
    list->size = 0;
}