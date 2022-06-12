#include <stdio.h>
#include<ctype.h>
#include "stackADT2.h"
int main()
{
    char ch;
    stack s = create(20);
    printf("Enter the RPN experation :");
    ch = getchar();
    while (ch != '\n')
    {
        if (isdigit(ch))
            push(s,digit_to_int(ch));
        else if (ch == '+')
        {
            item a = pop(s);
            item b = pop(s);
            push(s,(a + b));
        }
        else if (ch == '-')
        {
            item a = pop(s);
            item b = pop(s);
            push(s,(a - b));
        }
        else if (ch == '*')
        {
            item a = pop(s);
            item b = pop(s);
            push(s,(a * b));
        }
        else if (ch == '/')
        {
            item a  = pop(s);
            item b = pop(s);
            push(s,(a / b) );
        }
        else if (ch == '=')
        {
            printf("The answere is %d\n", pop(s));
            printf("Enter a RPN expression :");
            make_empty(s);
            char k;
            while((k  = getchar()) != '\n'){} 
        }
      

        ch = getchar();
       
        
    }
    destroy(s);


    return 0;
}
