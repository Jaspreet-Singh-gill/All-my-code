#include <stdio.h>
#include<ctype.h>
#include "queque.h"
int digit_to_int(char ch){
	return ch -'0';
}

int main()
{
    char ch;
    quque s = create();
    printf("Enter the RPN experation :");
    ch = getchar();
    while (ch != '\n')
    {
        if (isdigit(ch))
            edquque(s,digit_to_int(ch));
        else if (ch == '+')
        {
            item a = dlquque(s);
            item b = dlquque(s);
            edquque(s,(a + b));
        }
        else if (ch == '-')
        {
            item a = dlquque(s);
            item b = dlquque(s);
            edquque(s,(a - b));
        }
        else if (ch == '*')
        {
            item a = dlquque(s);
            item b = dlquque(s);
            edquque(s,(a * b));
        }
        else if (ch == '/')
        {
            item a  = dlquque(s);
            item b = dlquque(s);
            edquque(s,(a / b) );
        }
        else if (ch == '=')
        {
            printf("The answere is %d\n",dlquque(s));
            printf("Enter a RPN expression :");
        //   make_empty(s);





            char k;
            while((k  = getchar()) != '\n'){} 
        }
      

        ch = getchar();
       
        
    }
   destroy(s);

    return 0;
}
