#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c){\
  if(!space_char(c) && c != '\0'){
    return 1;
  }
  return 0;
}

char word_start(char *str){
  int i = 0;
  while(non_space_char(str[i])){
    i++;
  }
  if(space_char(str[i])){
    *str += 1;
    return *str;
  }else{
      return 0;
  }
}

char *word_terminator(char *word){
  int i = 0;
  while(non_space_char(word[i])){
    i++;
  }
  if(space_char(word[i]))
    return word + i;
  return 0;
}

int count_words(char *str){
  int count = 0;
  int i = 0;
  while(str[i] != '\0'){
    if(space_char(str[i])){
	count++;
    }
    i++;
  }
  count++;
  return count;
}

char *copy_str(char *inStr, short len){
  char *str = (char*)malloc(sizeof(char) * (len+1));
  for(int i = 0; i < len; i++){
    *(str + i) = *(inStr +i);
  }
  *(str + len) = '\n';
  return str;
}

int size = 0;

char **tokenize(char* str){
  int count = count_words(str);
  char **tokens = (char**)malloc(count*sizeof(char*));
  int sizeOfWord;
  
  for(int i = 0; i < count; i++){
    char *endOfWord = word_terminator(str);

    int count1 = 0;
    int count2 = 0;
    for(count1 = 0; str[count1] != '\n'; ++count1);
    if(endOfWord != 0){
      for(count2 = 0; endOfWord[count2] != '\n'; ++count2);
    }
    sizeOfWord = count1 - count2;
    
    char *word;
    word = copy_str(str, sizeOfWord);
    *(tokens + i) = word;

    if(endOfWord != 0 &&  space_char(*endOfWord)){
	*endOfWord++;
	str = endOfWord;
      }
  }
  
  size = count;
  return tokens;
}

void print_tokens(char **tokens){
  int count = 0;
  for(count = 0; count < size; ++count){
    printf("tokens[%d] = %s", count + 1, tokens[count]);
  }
}

void free_tokens(char **tokens){
  for(int i = 0; i < size; i++){
    free(*tokens+i);
  }
  free(tokens);
}
