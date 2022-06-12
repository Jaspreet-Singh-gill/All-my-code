#ifndef QUEQUE
#define QUEQUE
#include<stdbool.h>
typedef struct quque_type *quque;
typedef int item;

void edquque(quque q ,item i);
item dlquque(quque q);
item first_quque(const quque q);
item last_quque(const quque q);
bool is_empty(quque q);
quque create(void);
void destroy(quque q);


#endif
