#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


int main(int argc, char** argv) {

   printf("what is your status?\n");
   printf("1. Student \n2. Faculty or Staff \n3. Parking Police \n4. Management \n5. Exit \n");
   //printf("-->");
   int input;
   scanf("%d", &input);
   if(input<1 || input>5){
      printf("Wrong status option (number) input, try again\n");
      scanf("%d", &input);
   }
   
   switch(input){
      case 1: printf("Student>\n");
              printf("What would you like to do?\n");
              printf("1. Get a permit?\n");
              printf("2. Register a vehicle (up to 3)?\n");
              printf("3. View citation(s)?\n");
              printf("4. Go back?\n");
              int input1;
              scanf("%d", &input1);
              break;
      case 2: printf("Faculty/Staff>\n");
              printf("What would you like to do?\n");
              printf("1. Get a permit?\n");
              printf("2. Register a vehicle (up to 3)?\n");
              printf("3. View citation(s)?\n");
              printf("4. Go back?\n");
              int input2;
              scanf("%d", &input2);
              break;
      case 3: printf("Parking police>\n");
              printf("What would you like to do?\n");
              printf("1. Search registry?\n");
              printf("2. Issue a citation?\n");
              printf("3. Go back?\n");
              int input3;
              scanf("%d", &input3);
              break;
      case 4: printf("Management>");
              printf("What would you like to do?\n");
              printf("1. View lot status?\n");
              printf("2. Update lot status?\n");
              printf("3. View/update citation?\n"); //if citation is found delete or update citation
              printf("4. Go back?\n");
              int input4;
              scanf("%d", &input4);
              break;
      case 5: exit(0);
      default: printf("Invalid input\n");
               break;
   }


   return (EXIT_SUCCESS);
}