#include <ctype.h>
//stof converts string in scientific format into double
#include <stdio.h>

double stof(char s[]){
  double material, atof(char []), real, power = 10.0;
  material = 0.0;
  int i, j, e_index, sign;
  for(i = 0; isspace(s[i]); i++);
  for(j = i; s[j] != 'e' && s[j] != 'E'; j++);
  char mat[j - i];
  e_index = j;
  for(int k = 0; j - i > 0; k++, i++){
    mat[k] = s[i];
  }
  
  material = atof(mat);
  
  e_index++;
  sign = (s[e_index] == '-')?-1:1;
  real = s[e_index + 1] - '0';
  
  for(int k = e_index + 2; s[k] != '\0' && s[k] != ' ' && s[k] != '\n'; k++){
    real *= power;
    real += s[k] - '0';
    power *= 10.0;
  }
  
  power = 1.0;
  while(real > 0){
    power *= 10.0;
    real -= 1;
  }

  if(sign == -1)
    material /= power;
  else
    material *= power;

  return material;

}
