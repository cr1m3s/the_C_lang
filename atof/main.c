#include <stdio.h>
#define MAXLINE 100

int my_getline(char s[], int lim);

int main(){
  printf("You should use numbers in format: d.d{e/E}{+/-}d\n");
  printf("Start typing here: ");
  double sum, stof(char []);
  char line[MAXLINE];
  int my_getline(char line[], int max);

  sum = 0;
  while(my_getline(line, MAXLINE) > 0)
    printf("\tHere we go: %g\tenter what you want to add: ", sum += stof(line));
  return 0;
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
