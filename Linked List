#include <stdio.h>
#include <stdlib.h>

int choice;

// Singly Linked List node structure
struct singly_node{
  int data;
  struct singly_node *next;
};

// Doubly Linked List node structure
struct doubly_node{
  int data;
  struct doubly_node *next, *prev;
};

// Function to display the menu
void menu(void) {
  printf("\n1. Singly Linked List \n2. Doubly Linked List \n3. Circular Linked List \n4. Exit");
  printf("\nChoose an option: ");
  scanf("%d", &choice);
}

// Function to create and display Singly Linked List
void singly_linked_list(){
  printf("\n*** Singly Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      temp = new_node;
    }

    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Singly Linked list are...\n");
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to create and display Doubly Linked List
void doubly_linked_list(){
  printf("\n*** Doubly Linked List ***");
  int choice = 1;
  struct doubly_node *head = NULL, *new_node, *temp;
  
  while (choice == 1) {
    new_node = (struct doubly_node *)malloc(sizeof(struct doubly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      new_node->prev = temp;
      temp = new_node;
    }

    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Doubly Linked list are...\n");
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Function to create and display Circular Linked List
void circular_linked_list(){
  printf("\n*** Circular Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = head; // Point new node to the head to make it circular
    
    if (head == NULL) {
      head = new_node;
      temp = new_node;
    } else {
      temp->next = new_node;
      temp = new_node;
    }
    
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  // Displaying circular list
  if (head != NULL) {
    printf("\nThe elements in the Circular Linked List are...\n");
    temp = head;
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while (temp != head);  // Continue until we reach the head again
    printf("\n");
  }
}

int main() {
  while (1)  {
    menu();
    switch(choice) {
      case 1: 
        singly_linked_list();
        break;
      case 2: 
        doubly_linked_list();
        break;
      case 3: 
        circular_linked_list();
        break;
      case 4: 
        return 0;
      default: 
        printf("\nInvalid Option\n");
    }
  }
}
