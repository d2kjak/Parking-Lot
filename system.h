#ifndef _system
#define _system

char input[1000];
typedef struct vechile vechile;
typedef struct student student;
student*create_student( );
void add_student(student *);
void display_students_id(student*);
void delete_middle(student*);
student* find_student(student*, int);
void remove_student(student*,int);
int menu( );
void student_option(student*);
student* fake_db(student*);


#endif