#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int endindex(char source[], int start);
int startindex(char source[], int start);
int rightindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
  char line[MAXLINE];
  int found = 0;
  
  printf("simple pattern finder\n");
  printf("%s -- it's a pattern", pattern);
  printf("Here you can try to type something:\n");

  while(my_getline(line, MAXLINE) > 0)
    if(strindex(line, pattern) >= 0){
      printf("%s", line);
      int strind = strindex(line, pattern);
      int rightind = rightindex(line, pattern);
      int start = startindex(line, rightind);
      int end = endindex(line, rightind);
      printf("\n%d\n", strind);
      printf("\n%d\n", start);
      printf("\n%d\n", end);
      for(int i = start; i <= end; i++)
        printf("%c", line[i]);
      printf("\n");
      found++;
    }
  return found;
}

int my_getline(char s[], int lim){
  int c, i;

  i = 0;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}


int endindex(char s[], int start){
  int i;
  for(i = start; s[i] != ' ' && s[i] != '\n' && s[i] != '.' && s[i] != ',' && s[i] != '\0'; ++i)
    printf("\n %c === %d", s[i], i);
  printf("\n ~~~~~~~~~%d~~~~~~~~~~~~\n", i);
  return i - 1;
}

int startindex(char s[], int start){
  int i;
  for(i = start; i >= 0 && s[i] != ' ' && s[i] != '.' && s[i] != ','; i--);
  return i + 1;
}

int strindex(char s[], char t[]){
  int i, j, k;

  for(i = 0; s[i] != '\0'; i++){
    for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);

    if(k > 0 && t[k] == '\0')
      return i;
    }
  return -1;
}

//looking for matches one by one and return the most right 
int rightindex(char s[], char t[]){
  int i, j, k, result = -1;

  for(i = 0; s[i] != '\0'; i++){
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

    if(k > 0 && t[k] == '\0')
      result = i;
  }

  return result;
}
