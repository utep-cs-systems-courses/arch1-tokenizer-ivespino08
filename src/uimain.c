#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  struct s_List *list;
  list = init_history();
  while(1){
    char input[50];
    printf("Please input something\n");
    printf(">");
    fgets(input,100, stdin);
    char exit[4] = "exit";
    int i;
    for(i = 0; i < sizeof exit/sizeof *exit; i++){
      if(exit[i] != input[i])
	break;
    }
    if(i == 4){
      free_history(list);
      return 0;
    }
    
    if(input[0] == '!'){
      int id = input[1] - '0';
      char *str = get_history(list, id);
      char **tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
      
    }else{
      char **tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
      add_history(list, input);
    }
    
    printf("\nYou have input:\n");
    print_history(list);
  }
  return 0;
}
