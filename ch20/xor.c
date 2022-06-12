#include<stdio.h>
#include <ctype.h>
#define KEY '&'

int main()
{
  int org_char, new_char;
  while((org_char = getchar()) != EOF)
  {
    new_char = org_char ^KEY;
    if(isprint(org_char) && isprint(new_char))
    putchar(new_char) ;
    else
    putchar(org_char) ;
  }
 
  
  return 0;
  
}
