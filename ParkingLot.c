#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define bool int
#define true 1
#define false 0


int main(int argc, char** argv) {

   bool exit1 = true;
   
   while(exit1){
      bool exit2 = true;
      while(exit2){
         printf("\nwhat is your status?\n");
         printf("1. Student \n2. Faculty or Staff \n3. Parking Police \n4. Management \n5. Exit \n\n");
         //printf("-->");
         int input;
         scanf("%d", &input);
         if(input<1 || input>5){
            printf("Wrong status option (number) input, try again\n");
            scanf("%d", &input);
         }
         
         switch(input){
            case 1: printf("\n\nStudent>\n");
                    printf("What would you like to do?\n");
                    printf("1. Get a permit?\n");
                    printf("2. Register a vehicle (up to 3)?\n");
                    printf("3. View citation(s)?\n");
                    printf("4. Go back?\n");
                    int input1;
                    scanf("%d", &input1);
                    if(input1 == 4){
                        exit2 = false;
                    }
                    if(input1 == 3){
                    
                    }
                    if(input1 == 2){
                    
                    }
                    if(input1 == 1){
                    
                    }
                    break;
            case 2: printf("\n\nFaculty/Staff>\n");
                    printf("What would you like to do?\n");
                    printf("1. Get a permit?\n");
                    printf("2. Register a vehicle (up to 3)?\n");
                    printf("3. View citation(s)?\n");
                    printf("4. Go back?\n");
                    int input2;
                    scanf("%d", &input2);
                    if(input2 == 4){
                        exit2 = false;
                    }
                    if(input2 == 3){
                    
                    }
                    if(input2 == 2){
                    
                    }
                    if(input2 == 1){
                    
                    }
                    break;
            case 3: printf("\n\nParking police>\n");
                    printf("What would you like to do?\n");
                    printf("1. Search registry?\n");
                    printf("2. Issue a citation?\n");
                    printf("3. Go back?\n");
                    int input3;
                    scanf("%d", &input3);
                    if(input3 == 3){
                        exit2 = false;
                    }
                    if(input3 == 2){
                    
                    }
                    if(input3 == 1){
                    
                    }
                    break;
            case 4: printf("\n\nManagement>\n");
                    printf("What would you like to do?\n");
                    printf("1. View lot status?\n");
                    printf("2. Update lot status?\n");
                    printf("3. Search registry?\n");
                    printf("4. View/update citation?\n"); //if citation is found delete or update citation
                    printf("5. Go back?\n");
                    int input4;
                    scanf("%d", &input4);
                    if(input4 == 5){
                        exit2 = false;
                    }
                    if(input4 == 4){
                    
                    }
                    if(input4 == 3){
                    
                    }
                    if(input4 == 2){
                    
                    }
                    if(input4 == 1){
                    
                    }
                    break;
            case 5: exit(0);
                    //exit1 = false;
            default: printf("Invalid input\n");
                     break;
         }
      }
   }


   return (EXIT_SUCCESS);
}