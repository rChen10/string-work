#include <stdio.h>
#include <string.h>

int strlen$( char * );
char * strncpy$( char *dest, char *source, int n);
char * strcat$( char *dest, char *source);
int strcmp$( char *s1, char *s2 );
char * strchr$( char *s, char c );
char * strstr$( char *s1, char * s2 );


int strlen$( char * p){
  int count = 0;
  while(*p){
    count++;
    p++;
  }
  return count;
}


char * strncpy$( char *dest, char *source, int n){
  int count = 0;
  while(count < n && source[count]){
    dest[count] = source[count];
    count++;
  }
  return dest;
}

char * strcat$( char *dest, char *source){
  char *p;
  while(*dest++){
    p++;
  }
  while(*source++){
    *p= *source;
    p++;
  }
  return *dest;
}



int main(){
  char s1[100] = "doggy";
  char s2[100] = "cat";
  char s3[100] = "doggy"; //copy of s1
  char s4[100] = "doggy";
  char s5[100] = "cat";
  char s6[100] = "doggy";
  char s7[100] = "cat";
  
  printf("s1: [doggy]\n");
  printf("s2: [cat]\n");
  printf("\n");

  printf("Testing strlen(s1):\n");
  printf("[standard]: %d\n", strlen(s1));
  printf("[mine]: %d\n", strlen$(s1));
  
  printf("Testing strlen(s2):\n");
  printf("[standard]: %d\n", strlen(s2));
  printf("[mine]: %d\n", strlen$(s2));

  printf("Testing strncpy(s1, s2, 2):\n");
  printf("[standard]: %s\n", strncpy(s1, s2, 2));
  printf("[mine]: %s\n", strncpy$(s3, s2, 2));

  
  printf("Testing strcat(s4, s5):\n");
  printf("[standard]: %s\n", strcat(s4, s5));
  printf("[mine]: %s\n", strcat$(s6, s7));
}
