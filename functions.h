
struct node{
         int data;
         struct node*next;
};
struct node *head;


void addAtBeginning(int val){
         /*A function to add node at the beginning of the linked list*/
         struct node* temp;

         if(head == NULL){
                  head = (struct node*) malloc(sizeof(struct node)); // Allocate memory
                  head->data = val;
                  head->next = NULL;
                  return ;
         }

         temp = head;
         head = (struct node*) malloc(sizeof(struct node));
         head->data = val;
         head->next = temp;
}//add

void addAtEnd(int val){
         /*A function to add node at the end of the linked list*/
         struct node *trav,*temp;


         if(head==NULL){
                  head = (struct node*) malloc(sizeof(struct node));
                  head->next = NULL;
                  return ;
         }

         trav = head;

         while(trav->next != NULL)
                  trav = trav->next;
         temp = (struct node *)malloc(sizeof(struct node));
         temp->data = val;
         temp->next = NULL;
         trav->next = temp;

}


void printIterative(){
         struct node *trav; //traverser

         trav = head;

         while(trav != NULL){  //Traverse till the end
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


void deleteAtEnd() {
         struct node *curr,*prev;

         if(head == NULL){
                  printf("List is empty");
                  return ;
         }
         curr = head;
         prev = NULL;

         while( curr->next != NULL){
                  prev = curr;
                  curr = curr->next;
         }

         if(curr == head){
                  free(head);
                  head = NULL; //When there is only one node
                  }
         else{
                  free(prev->next);
                  prev->next = NULL;
         }

}

void deleteAtFront(){
         struct node *temp;
         if(head == NULL){
                  printf("List is empty");
                  return ;
         }
         temp = head;
         head = head->next;
         free(temp);
}

