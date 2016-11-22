//
//  main.c
//  se2
//
//  Created by David Giampa on 2016-11-20.
//  Copyright © 2016 David Giampa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct vechile
{
    char color[256];
    int year[256];
    char type_of_car[256];
    int permit_ID[256];
}vechile;

typedef struct student
{
    char name[256];
    int ID;
    double citation_balance;
    struct students*next;
    vechile vechelis[3];
}student;

student*create_student( )
{
    student*create=malloc(sizeof(student));
  
    memset(create->name, '0', 256);
    memset(create->vechelis->color, '0', 256);
    memset(create->vechelis->permit_ID, '0', 256);
    memset(create->vechelis->type_of_car, '0', 256);
    memset(create->vechelis->year, 0, 256);
    create->citation_balance=0.0;
    create->next=NULL;
    create->ID=0;
    return create;
}

int main(int argc, const char * argv[]) {

    student *p1=create_student();
    p1->ID=234;
    printf("%d",p1->ID);
    p1->vechelis->color[0]='b';
    printf("%c\n",p1->vechelis->color[0]);
    free(p1);
    
    return 0;
}
