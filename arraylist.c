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
        

  
}
  



void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
