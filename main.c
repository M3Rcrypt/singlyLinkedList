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


// More detailed implementation with sorting
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

void printList(struct Node *list){
  struct Node *p;
  p = list;
  printf("\nThe list = ");
  while(p != NULL){
    if(p->next == NULL) {
      printf("%d",p->data);
      p = p-> next;
    }
    else{
      printf("%d ---> ",p->data);
      p = p-> next;
    }
    
  }
}

void CreateList(struct Node** head){
  struct Node* p;
  struct Node* last;
  int n, i, x;
  printf("Declare the size of list: ");
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    printf("Please enter element %d: ", i+1);
    scanf("%d", &x);
    p = (struct Node*)malloc(sizeof(struct Node));
    p -> data = x;

    if(*head == NULL){
      *head = p;
      p -> next = NULL;
      last = p;
    }
    else{
      last -> next = p;
      p -> next = NULL;
      last = p;
    }
  }
}

void InsertAtBeginning(struct Node** head){
  int x;
  struct Node* p = (struct Node*)malloc(sizeof(struct Node));
  printf("\n\nPlease enter the number to be the first element of the list: ");
  scanf("%d",&x);
  p->next = *head;
  *head = p;
  p->data = x;
}

void InsertAtEnd(struct Node** head){
  int x;
  struct Node* temp = *head;
  struct Node* p = (struct Node*)malloc(sizeof(struct Node));
  printf("\n\nPlease enter the number to be the last element of the list: ");
  scanf("%d",&x);
  while(temp->next != NULL){
    temp = temp->next;
  }
  p->data = x;
  p->next = NULL;
  temp->next = p;
}

int calculateSize(struct Node** head){
  int count = 0;
  struct Node *p = *head;
  while(p != NULL){
    p = p->next;
    count++;
  }
  return count;
}

void InsertAtPosition(struct Node** head){
  int count, pos, val;
  printf("\n\nPlease enter the position: ");
  scanf("%d",&pos);
  printf("\nPlease enter the value: ");
  scanf("%d", &val);
  
  if(pos<1 || pos > calculateSize(head)){
    printf("\nThe position must be between 1 and %d", calculateSize(head));
  }
  else if(pos == 1){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->next = *head;
    *head = p;
    p->data = val;
  }
  else if(pos == calculateSize(head)){
    struct Node* temp = *head;
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    while(temp->next != NULL){
      temp = temp->next;
    }
    p->data = val;
    p->next = NULL;
    temp->next = p;
  }
  else{
    struct Node* p = *head;
    for(count=1;count<pos-1; count++){
      p = p->next;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = p->next;
    p->next = temp;
  }
}

void DeleteAtPosition(struct Node** head){
  int count, pos;
  printf("\n\nPlease enter the position to delete: ");
  scanf("%d", &pos);
  if(pos<1 || pos > calculateSize(head)){
    printf("\nThe position must be between 1 and %d", calculateSize(head));
  }
  else if(pos == 1){
    struct Node* temp = *head;
    (*head) = temp->next;
    free(temp);
  }
  else if(pos == calculateSize(head)){
    struct Node* temp = *head;
    while((temp->next)->next != NULL){
      temp = temp->next;
    }
    temp->next = NULL;
    free(temp->next);
  }
  else{
    struct Node* temp = *head;
    int i;
    for(i=1;i<pos-1;i++){
      temp = temp->next;
    }
    struct Node* pre = temp;
    struct Node* post = (temp->next)->next;
    struct Node* actual = temp->next;
    pre->next = post;
    free(actual);
  }
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
  
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
  
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return result;
}

void MergeSort(struct Node** head){
  struct Node* a, *b;
  struct Node* div = *head;
  int mid;
  if(calculateSize(head) % 2 == 0){
    mid = calculateSize(head) / 2;
  }
  else{
    mid = (int)ceil((calculateSize(head)/2) + 1);
  }

  if (((*head) == NULL) || ((*head)->next == NULL)) {
    return;
  }
  int i;
  for(i = 1; i < mid; i++){
    div = div -> next;
  }
  a = *head;
  b = div->next;
  div -> next = NULL;

  MergeSort(&a);
  MergeSort(&b);

  *head = SortedMerge(a,b);
}

void SearchElement(struct Node* head){
  struct Node* temp = head;
  int count = 1, flag = 0;
  int x;
  printf("\n\nPlease enter the element to be found: ");
  scanf("%d",&x);
  while(temp != NULL){
    if(temp->data == x){
      printf("\nElement %d in position %d",x,count);
      flag++;
    }
    temp = temp->next;
    count++;
  }
  if(flag == 0){
    printf("\nElement %d is not in the list.", x);
  }
}

void ReverseList(struct Node** head){
  struct Node *prev, *current, *next;
  current = *head;
  prev = NULL;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

int main(void) {
  head = NULL;
  CreateList(&head);
  printList(head);
  InsertAtBeginning(&head);
  printList(head);
  InsertAtEnd(&head);
  printList(head);
  printf("\n\nSize of the list is %d", calculateSize(&head));
  InsertAtPosition(&head);
  printList(head);
  DeleteAtPosition(&head);
  printList(head);
  MergeSort(&head);
  printList(head);
  SearchElement(head);
  ReverseList(&head);
  printList(head);
}*/
