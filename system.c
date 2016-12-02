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
#include "system.h"

char input[1000];
typedef struct vechile
{
    char color[256];
    int year;
    char type_of_car[256];
    int permit_ID[256];
}vechile;

typedef struct student
{
    char name[256];
    char lastname[256];
    int ID;
    double citation_balance;
    struct student*next;
    struct student*back;
    vechile vechelis[3];
}student;
/////////////////////////////////////////////////////dynamically allocates memory for new student/////////////////////////////////////////////
student*create_student( )
{
    student*create=malloc(sizeof(student));
  
    memset(create->vechelis->color, '0', 256);
    memset(create->vechelis->permit_ID, '0', 256);
    memset(create->vechelis->type_of_car, '0', 256);
    create->vechelis->year=0;
    create->citation_balance=0.0;
    create->next=NULL;
    create->back=NULL;
    create->ID=0;
    return create;
}
///                     ///////////////////////////////////   adds a new student to a double linked list/////////////////////////
void add_student(student *old)
{
    student *new=create_student( );
    old->next=new;
    new->back=old;
}
///                     //////////////////////////////////  displays the double linked list ///////////////////////////////////////

void display_students_id(student*info)
{
    printf("\n\tName\t\t ID\t\t Make\t year\t citation\n");
    printf("--------------------------------------------------\n");
    while(info->back!=NULL)
    {
        info=info->back;
    }
    
    while(info->next!=NULL)
    {
    printf(" %s\t%s\t %d\t %s\t %d\t %.2f\n",info->name,info->lastname,info->ID,info->vechelis->type_of_car,info->vechelis->year,info->citation_balance);
        info=info->next;
    }
    printf(" %s\t%s\t %d\t %s\t %d\t %.2f\n",info->name,info->lastname,info->ID,info->vechelis->type_of_car,info->vechelis->year,info->citation_balance);
   
}
 
///                 //////////////  //////////////////////////////////  //////////////////////////////////  /////////
///                ////////////////  ////////////////   remove a student from the linked list//////////////  ////////
///               ////////////////  //////////////////////////////////  //////////////////////////////////  /////////

void delete_middle(student*remove)
{

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
int menu( )
{
    int option;
    printf("\n\n\n");
    printf("press 1 to enter a new student and vechile info\n");
    printf("press 2 to enter a new falcuilty and staff vechile info\n");
    printf("press 3 for  department police\n");
    printf("press 4 for mangment\n");
    printf("press 5 to display Database\n");
    scanf("%d",&option);

    
    return option;
}
void student_option(student*person)
{
  
    add_student(person);
    person=person->next;
    printf("enter full name\n");
    scanf("%s",person->name);
    scanf("%s",person->lastname);
    printf("enter student ID\n");
    scanf("%d",&person->ID);
    printf("enter vechile make\n");
    scanf("%s",person->vechelis->type_of_car);
    printf("enter year made\n");
    scanf("%d",&person->vechelis->year);
    printf("enter color of vechile\n");
    scanf("%s",person->vechelis->color);
   
    
}
student* fake_db(student*person)
{
    person=create_student();
    strcpy(person->name, "david");
    strcpy(person->lastname, "giampa");
    person->ID=1234;
    person->citation_balance=25.00;
    strcpy(person->vechelis->type_of_car,"honda");
    person->vechelis->year=1994;
    
    add_student(person);
    person=person->next;
    strcpy(person->name, "Johnny");
    strcpy(person->lastname, "cash");
    person->ID=1235;
    person->citation_balance=20.00;
    strcpy(person->vechelis->type_of_car,"toyata");
    person->vechelis->year=2000;
    //person=person->next;
    
    add_student(person);
    person=person->next;
    strcpy(person->name, "Travis");
    strcpy(person->lastname, "Vaughn");
    person->ID=1236;
    person->citation_balance=20.00;
    strcpy(person->vechelis->type_of_car,"toyata");
    person->vechelis->year=2000;
 
    
    add_student(person);
    person=person->next;
    strcpy(person->name, "Stan");
    strcpy(person->lastname, "TheMan");
    person->ID=1237;
    person->citation_balance=10.00;
    strcpy(person->vechelis->type_of_car,"lexus");
    person->vechelis->year=2006;

    
    add_student(person);
    person=person->next;
    strcpy(person->name, "Justin");
    strcpy(person->lastname, "Bieber");
    person->ID=1238;
    person->citation_balance=100000.00;
    strcpy(person->vechelis->type_of_car,"LFA");
    person->vechelis->year=2010;
    return person;
    
}
int main(int argc, const char * argv[])
{
  
    int choice;
    student* person;
    person=fake_db(person);
    
    while(1)
    {
  
       choice=menu();
    if (choice==1||choice==2) {

        student_option(person);
    }
    else if (choice==5)
    {
        display_students_id(person);
    }
    }
    
    return 0;
}
