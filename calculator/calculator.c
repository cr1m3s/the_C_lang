#include <stdio.h>
#include <stdlib.h> //atof will be used from standart lib

#define MAXOP 100 //max size of operand or operator
#define NUMBER '0' //signal that number was found

int getop(char []);
void push(double);
double pop(void);

//reverse Polish calculator
int main(){
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    switch(type){
      case NUMBER:
        push(atof(s));
        printf("~~%d~~", type);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("\nError: zero division\n");
        break;
      case '\n':
        printf("\t%.8g\t", pop());
        break;
      default:
        printf("\nError unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("\nError: stack full, can't push %g\n", f);
}

double pop(void){
  if(sp > 0)
    return val[--sp];
  else{
    printf("\nError: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

//getop get next operator or numeric operand
int getop(char s[]){
  int i, c;
  while(((c = getch()) == ' ' && (s[0] = c) == ' ') || c == '\t');

  s[1] = '\0';
  
  if(!isdigit(c) && c != '.')
    return c; 
  i = 0;
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()));

  if(c == '.')
    while(isdigit(s[++i] = c = getch()));

  s[i] = '\0';
  if(c != EOF)
    ungetch(c);

  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
  return(bufp > 0)?buf[--bufp]:getchar();
}

void ungetch(int c){
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
