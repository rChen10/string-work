#include <stdio.h>
#include <string.h>
#include "header.h"

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
  char *p = dest;
  while(*dest){
    dest++;
  }
  while(*source){
    *dest= *source;
    source++;
    dest++;
  }
  return p; 
}

int strcmp$( char *s1, char *s2) {
  while(*s1==*s2 && *s1 && *s2){
    s1++;
    s2++;
  }
  if(*s1<*s2){
    return -1;
  }
  if(*s1==*s2){
    return 0;
  }
  else{
    return 1;
  }
}

char * strchr$( char *s, char c ){
  while(*s){
    if( *s==c){
      return s;
    }
    s++;
  }
  return 0;
}

char * strstr$( char *s1, char * s2 ){
 char  *p= strchr(s1, s2[0]);
 char *g = s2;
  if(*p){
    while(*p==*s2 && *p && *g){
      p++;
      g++;
    }
    if (p[-1] == g[-1]){
      return strchr(s1, s2[0]);
    }
    if (*p){
      return 0;
    }
  }
 return strstr$(p,s2);
      }
    
      
	  
  



int main(){
  char s1[100] = "doggy";
  char s2[100] = "cat";
  char s3[100] = "doggy"; //copy of s1
  char s4[100] = "doggy";
  char s5[100] = "cat";
  char s6[100] = "doggy";
  char s7[100] = "cat";
  char s8[100] = "doggy";
  char s9[100] = "cat";
  char s10[100]= "kittycat";

  
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

  
  printf("Testing strcat(s1, s2):\n");
  printf("[standard]: %s\n", strcat(s4, s5));
  printf("[mine]: %s\n", strcat$(s6, s7));

  printf("Testing strcmp$ (s1, s2):\n");
  printf("[standard]: %d\n", strcmp(s8, s9));
  printf("[mine]: %d\n", strcmp$(s8, s9));

  printf("Testing strcmp$ (s1, s1):\n");
  printf("[standard]: %d\n", strcmp(s8, s8));
  printf("[mine]: %d\n", strcmp$(s8, s8));

  printf("Testing strchr$ (s1, t):\n");
  printf("[standard]: %s\n", strchr(s8,'g'));
  printf("[mine]: %s\n", strchr$(s8,'g'));

  printf("Testing strstr$ (\"kittycat\", s2):\n");
  printf("[standard]: %s\n", strstr(s10,s9));
  printf("[mine]: %s\n", strstr$(s10,s9));
  

}
