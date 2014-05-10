/*
A Basic program to illustrate linked lists:
This program shows how to add a new node to the linked list and print the linked list:

         print Functions:
                  Iterative and Recursive approaches shown.
                  Traverse till the end and print all the <data> values.
         add Function:
                  Add a new node to the linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{                 //Defining our linked list
         int data;
         struct node * next; //Pointer to the next node
};

struct node *head;

/*Function Declarations*/
void add(int);
void printIterative();
void printRecursive(struct node *);


int main() {
         int iter;

         head = NULL;  // Empty List Initially.

         for(iter = 0;iter < 20;iter++){
                  add( rand()%500 );
                  printIterative();
         }
printf("List printed in recursive manner: \n");
printRecursive(head);
         return 0;
}

void add(int val){
         /*A function to add node at the beginning of the linked list*/
         struct node* temp;

         if(head == NULL){
                  /*Initially when the list is empty*/
                  head = (struct node*) malloc(sizeof(struct node)); // Allocate memory
                  head->data = val;
                  head->next = NULL;
                  return ;
         }
         /*Adding a new node at the beginning of the list
         EX:
         let the list be 1->3->5->8->10
         => head := 1->3->5->8->10
         */
         temp = head;  /*After this line: temp := 1->3->5->8->10 and head := 1->3->5->8->10*/
         head = (struct node*) malloc(sizeof(struct node)); //*After this line: temp := 1->3->5->8->10 and head := an uninitialised new node*/
         head->data = val; /* Let us take val = 100 ,for example*/
         head->next = temp; /* temp := 1->3->5->8->10 and head := 100->1->3->5->8->10*/
}//add

void printIterative(){
         struct node *trav; //traverser

         trav = head;

         while(trav != NULL){  //Traverse till the end of the linked list
                  printf("%d ",trav->data);
                  trav = trav->next;
         }
         printf("\n");
}

void printRecursive(struct node *temp){
         if(temp == NULL)
                  return;
         printf("%d ",temp->data);
         printRecursive(temp->next);
}
