#include "manager.h"
#include <stdio.h>
void print(char ch)
{
    printf("Module %c is interested in the event",ch);
}

//void(*ptr)(char)=&print;

void create(int num)
{
    createnode(num);
}

void subscribe()
{
    void subscribeEvent();
}
/*
void publish(int num)
{
    void publishEvent(num,&print);
}
*/
