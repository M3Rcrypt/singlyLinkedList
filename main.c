#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Struct for Linked List implementation
struct Node{
  int data;
  struct Node* link;
};

struct Node* head;

// Linked list creation
struct Node* CreateLinkedList(struct Node* list){
  struct Node* last;
  struct Node* p;
  printf("Please enter the size of Linked List: ");
  int size, num;
  scanf("%d", &size);
  
  for(int i = 0; i < size; i++){
    p = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter an element: ");
    scanf("%d", &num);
    p->data = num;
      if(list == NULL){
        list = p;
        p -> link = NULL;
        last = p;
      }
      else{
        last -> link = p;
        p -> link = NULL;
        last = p;
      }
  }
  return list;
}

// printing the linked list
void PrintLinkedList(struct Node* head){
  struct Node* temp;
  temp = head;
  printf("\n");
  while(temp != NULL){
    printf(" %d",temp->data);
    temp = temp->link;
  }
  printf("\n");
}

// insert an element to the position n (index + 1)
void InsertNthPosition(struct Node** head, int data, int pos){
  struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
  temp1 -> data = data;
  temp1 -> link = NULL;
  if(pos == 1){
    temp1->link = *head;
    *head = temp1;
    return;
  }
  struct Node* temp2 = *head;
  for(int i = 0; i < pos-2; i++){
    temp2 = temp2->link;
  }
  temp1->link = temp2->link;
  temp2 -> link = temp1;
}

// insert an element to the beginning (index = 0)
void InsertBeginning(struct Node** head, int x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->link = *head;
  *head = temp;
}

// remove an element from position n (index + 1)
void DeleteNthPosition(struct Node** head, int pos){
  struct Node* temp1 = *head;
  if(pos == 1){
    *head = temp1 -> link;
    free(temp1);
    return;
  }

  for(int i = 0; i < pos-2; i++){
    temp1 = temp1->link;
  }
  struct Node* temp2 = temp1->link;
  temp1 -> link = temp2 -> link;
  free(temp2);

}

// reverse the linked list iteratively (10, 15, 2, 8 -> 8, 2, 15, 10)
void ReverseList(struct Node** head){
  struct Node* prev; 
  struct Node* current ;
  struct Node* next;
  current = *head;
  prev = NULL;
  while(current != NULL){
    next = current->link;
    current -> link = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

// reverse the linked list recursively
void RecursiveReverseList(struct Node *p){
  
  if(p->link == NULL){
    head = p;
    return;
  }
  RecursiveReverseList(p->link);
  struct Node* q = p->link;
  q->link = p;
  p->link = NULL;
}

// main function to exhibit all the functions
int main(){
  
  struct Node* list = NULL;
  head = CreateLinkedList(head);
  PrintLinkedList(head);
  int a;
  printf("\nPlease enter an element to add the beginning of linked list: ");
  scanf("%d",&a);
  InsertBeginning(&head,a);
  PrintLinkedList(head);
  printf("\nPlease enter an element and a position to add this element to linked list: ");
  int b,c;
  scanf("%d %d", &b,&c);
  InsertNthPosition(&head,b,c);
  PrintLinkedList(head);
  printf("\nPlease enter a position to delete element at that position: ");
  int d;
  scanf("%d",&d);
  DeleteNthPosition(&head,d);
  PrintLinkedList(head);
  printf("\nLimked List after reversed :");
  RecursiveReverseList(head);
  PrintLinkedList(head);
}