#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char *array){
  int len = 0;
  while (array[len] != 0){
    len++;
  }
  return len;
}

char *cpystr(char *dest, char *source){
  int x = 0;
  int y = 0;
  for (x; x < length(dest); x++)
    dest[x] = source[x];
  if (length(dest) > length(source)){
    int y = length(source);
    for (y; y < length(dest); y++)
      dest[y] = 0;
  }
  return dest;
}

char *catnstr(char *dest, char *source, int n){
  int x = 0;
  int y = length(dest);
  for (x; x < n + 1; x++){
      dest[y + x] = source[x];
  }
  return dest;
}

int cmpstr(char *s1, char *s2){
  int x = 0;
  while (s1[x] == s2[x]){
    x++;
  }
  return (s1[x] - s2[x]);
}

char *chrstr(char *s, char c){
  while (*s){
    if (*s == c)
      return s;
    s++;
  }
  return NULL;
}

int main(){
  char string1[50] = "HELLO";
  char string2[20] = "hello ";
  char string3[20] = " I am Ceming";
  char string4[20] = "awake";

  char string5[50] = "HI";
  char string6[20] = "hi ";
  char string7[20] = "I'm Ceming";
  char string8[20] = "awaken";
  
  char string9[20] = "HelloIamCeming";

  printf("My length of HELLO is %d.\n", length(string1));
  printf("Built-in: length of HI is %d.\n\n", strlen(string5));

  printf("HELLO copied into hello: %s.\n", cpystr(string1, string2));
  printf("Built-in: HI copied into hi: %s.\n\n", strcpy(string5, string6));
	 
  printf("Add (I am Ceming) to hello(n=11): %s.\n", catnstr(string1, string3, 11));
  printf("Add (I am Ceming) to hello(n=10): %s.\n\n", catnstr(string1, string3, 10));
  printf("Built-in: Add (I'm Ceming) to hello(n=10): %s.\n", strncat(string5, string7, 10));
  printf("Built-in: Add (I'm Ceming) to line above^(n= 9): %s.\n\n", strncat(string5, string7, 9));

  printf("Compare awake to awaken: %d.\n", cmpstr(string4,string8));
  printf("Built-in: compare awake to awaken: %d.\n\n", cmpstr(string4,string8));

  printf("The string 'o' and after 'o' in HelloIamCeming: %s.\n", chrstr(string9, 'o'));
  printf("Built-in: the string 'o' and after 'o' in HelloIamCeming: %s.\n", strchr(string9, 'o'));
    
  return 0;
}
    
