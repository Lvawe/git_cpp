#include <stdio.h>
#include <stdlib.h>
struct pupil {
    char name[20];
    int age;
    int sex;
} pup[5], *p=pup;

void fun ( int  *p )
{ (*p)++;
}

main(  )

{ int a=5;

  fun(&a);
    
  printf("%d",a);
    
}
