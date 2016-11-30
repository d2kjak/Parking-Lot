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

char input[1000];
typedef struct vechile
{
    char color[256];
    int year[256];
    char type_of_car[256];
    int permit_ID[256];//switch to student id (to be same as permit id)
}vechile;

typedef struct student
{
    char name[256];
    int ID;
    double citation_balance;
    struct students*next;
    vechile vechelis[3];
}student;

student* create_student( )
{
    struct student*next;
    struct student*back;
    vechile vechelis[3];
}student;
/////////////////////////////////////////////////////dynamically allocates memory for new student/////////////////////////////////////////////
student*create_student( int id)
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

///                     ///////////////////////////////////   adds a new student to a double linked list/////////////////////////
void add_student(student *old,int num)
{
    student *new=create_student(num);
    old->next=new;
    new->back=old;
}
///                     //////////////////////////////////  displays the double linked list ///////////////////////////////////////
void display_students_id(student*info)
{
    while(info->back!=NULL)
    {
        printf("%d\n",info->ID);
        info=info->back;
    }
      printf("%d\n",info->ID);
    
    while(info->next!=NULL)
    {
        printf("%d\n",info->ID);
        info=info->next;
    }
    printf("%d\n",info->ID);
}
///                ///////////////  //////////////////////////////////  //////////////////////////////////  /////////
///                 ////////////////  ////////////////   remove a student from the linked list//////////////  /////////
///               ////////////////  //////////////////////////////////  //////////////////////////////////  /////////

void delete_middle(student*remove)
{
    /*
    printf("current %d\n",remove->ID);
     printf("next %d\n",remove->next->ID);
    printf("back %d \n",remove->back->ID);
     */
   
    student*front_ptr=remove->next;
    student*back_ptr=remove->back;
    
    front_ptr->back=remove->back;
    back_ptr->next=front_ptr;
    
    remove->next=NULL;
    remove->back=NULL;
    free(remove);
}
student* find_student(student*remove, int target_num)
{
    while (remove!=NULL) {
        
        if(remove->ID==target_num)
        {
            delete_middle(remove);
            return remove;
            break;
        }
        remove=remove->back;
    }
    return NULL;
}
void remove_student(student*remove,int kill)
{
    remove=find_student(remove, kill);
}

int main(int argc, const char * argv[])
{
    student* info;
    info=create_student(10);
   
    add_student(info,6);
    info=info->next;
    
    add_student(info,7);
    info=info->next;
    
    add_student(info,11);
    info=info->next;

    remove_student(info,6);
     remove_student(info,7);
   display_students_id(info);
    
    return 0;
}
