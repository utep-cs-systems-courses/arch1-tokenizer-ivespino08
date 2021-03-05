#include "history.h"
#include "stdio.h"
#include "stdlib.h"

List* init_history(){
  struct s_List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  struct s_Item *root = list->root;
  
  int len = 0;
  while(str[len] != '\0'){
    len++;
  }
  char *str_copy = (char*)malloc(sizeof(char) * len);
  
  for(int i = 0; i < len; i++){
    *(str_copy +i) = str[i];
  }  
  struct s_Item *new = malloc(sizeof(Item));
  new->id = 1;
  new->str = str_copy;
  new->next = NULL;

  struct s_Item *tmp = root;
  if(tmp != NULL){
    while(tmp->next != NULL){
      tmp = tmp->next;
      new->id++;
    }
    new->id++;
    tmp->next = new;
    list->root = root;
  }else{
    list->root = new;
  }
}

char *get_history(List *list, int id){
  struct s_Item *tmp = list->root;
  while(tmp->id < id){
    tmp = tmp->next;
  }
  return tmp->str;
}

void print_history(List *list){
  if(list->root == NULL){
    return;
  }
  struct s_Item *tmp = list->root;
  while(tmp != NULL){
    printf("%d. %s",tmp->id, tmp->str);
    tmp = tmp->next;
  }
}

void free_history(List *list){
  struct s_Item *root = list->root;
  while(root != NULL){
    free(root->str);
    struct s_Item *tmp = root;
    root = root->next;
    free(tmp);
  }
  free(list);
}
