/*
This program is an extension to ll_1.c
This program has a new function printBackwards(<parameters>) which prints the given list from back to the front
         ex: if the list is 1->4->2->3
                  printBackwards(<parameters>) will print 3 2 4 1
         It's a Recursive function similar to printRecursive(<parameters>)
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
void printBackwards(struct node*);

int main() {
         int iter;

         head = NULL;  // Empty List Initially.

         for(iter = 0;iter < 10;iter++){
                  add( rand()%500 );

         }
printf("Linked List from start to end: \n");
printRecursive(head);

printf("Linked List from end to start: ");
printBackwards(head);
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
         if(temp == NULL){   //BaseCase
                  printf("\n");
                  return;
         }

         printf("%d ",temp->data);
         printRecursive(temp->next);
}


void printBackwards(struct node *temp){
         if(temp==NULL){
                  printf("\n");
                  return;
         }

         printBackwards(temp->next);
         printf("%d ",temp->data);
}
