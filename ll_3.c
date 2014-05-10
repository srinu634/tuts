/*
This program shows how to delete a node in a linked list
Make sure you have functions.h in the same folder   -> This is a user defined header file

1)         This program introdues you to deleting a node at the front of the linked list
           and end of the linked list
2)         As we have already seen how to add at the beginning  ,
           In this program we illustrate adding a new node at the end
           see the functions.h for the function implementations.
*/

#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

void delete_node(int val)
{
return 0;
}


int main() {
         int iter;

         head = NULL;  // Empty List Initially.


         for(iter = 0;iter < 1;iter++)
                  addAtEnd( rand()%100 );

         printf("Linked List is : \n");
         printIterative( );


         deleteAtFront();
         printf("After Deleting the first node : \n");
         printIterative( );



         deleteAtEnd();
         printf("After Deleting the last node: \n");
         printIterative( );


         return 0;
}

