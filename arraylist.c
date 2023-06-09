#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list= (ArrayList*) malloc(sizeof(ArrayList));
  
  if( list == NULL){
    return NULL;
  }  
  list->data = (void*)malloc(sizeof(void*) * 2);
  if(list->data == NULL){
    free(list);
    return NULL;
  }
  list->capacity = 2;
  list->size = 0;
   return list; 
}


void append(ArrayList* l, void* data) {
  if (l == NULL) {
      return; 
  }
  if (l->size >= l->capacity) {
    int nuevaCap = l->capacity * 2; 
     void* nueData = realloc(l->data, nuevaCap * sizeof(void*));
    if (nueData == NULL) {
        return; 
    }
    l->data = nueData; 
    l->capacity = nuevaCap; 
  }
  l->data[l->size] = data;
  l->size++;           
}
  
void push(ArrayList * l, void * data, int i){
  if (i >= l->size) {
      return; 
  } 
  if (l->size == l->capacity) {
    l->capacity *= 2;
    void **Dato = malloc(l->capacity * sizeof(void*));
    
    for (int k = 0; k < l->size; k++) {
            Dato[k] = l->data[k]; 
    }  
    free(l->data);
    l->data = Dato;
  }  
  ;
  for (int k = l->size - 1; k >= i; k--) {
        l->data[k + 1] = l->data[k];
  }
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList* l, int i) {
  if (i < 0) {
      i = l->size + i;
  }
  if (i >= l->size || i < 0) {
      return NULL;
  }
  void* dato = l->data[i];
  for (int j = i; j < l->size - 1; j++) {
    l->data[j] = l->data[j + 1];
  }
  l->size--;
  return dato;
}

void* get(ArrayList * l, int i){
  if (i < 0) {
      i = get_size(l) + i;
  }
  if (i >= l->size) {
    return NULL;
  }
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  if(l == NULL){
    return;
  }
  l -> size =0;
  l -> capacity=2;
  free(l->data);
  l->data = realloc(l->data, sizeof(void *) * l->capacity);
}
