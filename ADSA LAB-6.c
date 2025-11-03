Q1

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", data);
}

// Insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        head = newNode;
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end.\n", data);
}

// Delete a node by value
void deleteNode(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // If the node to delete is the head
    if (temp->data == data) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("%d deleted.\n", data);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != data)
        temp = temp->next;

    if (temp == NULL) {
        printf("%d not found in list.\n", data);
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("%d deleted.\n", data);
}

// Display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter node value to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 4:
                displayList();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

OUTPUT:
--- Doubly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Delete a Node
4. Display List
5. Exit
Enter your choice: 1
Enter data: 10
10 inserted at beginning.

Enter your choice: 2
Enter data: 20
20 inserted at end.

Enter your choice: 2
Enter data: 30
30 inserted at end.

Enter your choice: 4
Doubly Linked List: 10 20 30

Enter your choice: 3
Enter node value to delete: 20
20 deleted.

Enter your choice: 4
Doubly Linked List: 10 30

Q2

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at a specific position
void insertAtPosition(int data, int position) {
    struct Node* newNode = createNode(data);

    // Case 1: Insert at the beginning
    if (position == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    int i;
    // Traverse to the node just before the desired position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    // Case 2: Insert in the middle or at the end
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Function to print the doubly linked list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(30, 3);
    insertAtPosition(15, 2); // Insert 15 at position 2
    display();

    return 0;
}

OUTPUT:
Doubly Linked List: 10 15 20 30 

Q3

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete the first occurrence of a given value
void deleteByValue(int value) {
    struct Node* temp = head;

    // Search for the node to delete
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    // Value not found
    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    // Case 1: Deleting the head node
    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    // Case 2: Deleting a middle or last node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

// Function to display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Before deletion:\n");
    display();

    deleteByValue(30);  // Delete first occurrence of 30

    printf("After deleting 30:\n");
    display();

    return 0;
}

OUTPUT:
Before deletion:
Doubly Linked List: 10 20 30 40 50 
After deleting 30:
Doubly Linked List: 10 20 40 50

Q4

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to reverse the doubly linked list in place
void reverseList() {
    struct Node* current = head;
    struct Node* temp = NULL;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to next node (which is prev after swap)
    }

    // Before exiting, adjust head
    if (temp != NULL)
        head = temp->prev;
}

// Function to display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Original list:\n");
    display();

    reverseList();

    printf("Reversed list:\n");
    display();

    return 0;
}

OUTPUT:

Original list:
Doubly Linked List: 10 20 30 40 50 
Reversed list:
Doubly Linked List: 50 40 30 20 10 

Q5

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find length and middle node
void findLengthAndMiddle() {
    struct Node* slow = head;
    struct Node* fast = head;
    int length = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Find length using traversal
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Find middle using two-pointer method
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Length of the list: %d\n", length);
    printf("Middle node value: %d\n", slow->data);
}

// Function to display the list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    display();
    findLengthAndMiddle();

    return 0;
}

OUTPUT:
Doubly Linked List: 10 20 30 40 50 
Length of the list: 5
Middle node value: 30

Q6

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning of the circular linked list
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Circular link
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)  // Find the last node
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;  // Update head to new node
}

// Insert at the end of the circular linked list
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        newNode->next = head; // Circular link
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)  // Find the last node
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    insertAtEnd(40);

    display();

    return 0;
}

OUTPUT:

Circular Linked List: 5 10 20 30 40 

Q7

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end (for setup/demo)
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Function to insert a new node after a given node value
void insertAfter(int key, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Node with value %d not found in the list\n", key);
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printf("Before insertion:\n");
    display();

    insertAfter(20, 25); // Insert 25 after node with data 20

    printf("After inserting 25 after 20:\n");
    display();

    insertAfter(50, 60); // Try inserting after non-existing node

    return 0;
}

OUTPUT:

Before insertion:
Circular Linked List: 10 20 30 40 
After inserting 25 after 20:
Circular Linked List: 10 20 25 30 40 
Node with value 50 not found in the list

Q8

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end (for demo/setup)
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Function to delete a node with a specific value
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *curr = head, *prev = NULL;

    // Case 1: If the node to be deleted is the only node
    if (head->next == head && head->data == key) {
        free(head);
        head = NULL;
        return;
    }

    // Case 2: If the node to delete is the head node
    if (head->data == key) {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Case 3: Deleting a non-head node
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != head);

    printf("Node with value %d not found in the list\n", key);
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Original list:\n");
    display();

    deleteByValue(10);  // Delete head
    printf("After deleting 10:\n");
    display();

    deleteByValue(30);  // Delete middle node
    printf("After deleting 30:\n");
    display();

    deleteByValue(50);  // Delete last node
    printf("After deleting 50:\n");
    display();

    deleteByValue(100); // Try deleting non-existing node

    return 0;
}

OUTPUT:

Original list:
Circular Linked List: 10 20 30 40 50 
After deleting 10:
Circular Linked List: 20 30 40 50 
After deleting 30:
Circular Linked List: 20 40 50 
After deleting 50:
Circular Linked List: 20 40 
Node with value 100 not found in the list

Q9

#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check whether a linked list is circular
int isCircular(struct Node* head) {
    if (head == NULL)
        return 0;  // Empty list is not circular

    struct Node* temp = head->next;

    // Traverse until we either reach head again or NULL
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    // If temp == head, it’s circular; otherwise, not
    return (temp == head);
}

// Function to display the list (for demonstration)
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    int count = 0;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
        if (count > 20) break; // safety to avoid infinite loop
        if (temp == head)
            break;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a non-circular linked list
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);

    printf("First list:\n");
    display(head1);
    if (isCircular(head1))
        printf("The first list is circular.\n");
    else
        printf("The first list is NOT circular.\n");

    // Create a circular linked list
    struct Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    head2->next->next->next = head2; // make circular

    printf("\nSecond list:\n");
    display(head2);
    if (isCircular(head2))
        printf("The second list is circular.\n");
    else
        printf("The second list is NOT circular.\n");

    return 0;
}

OUTPUT:

First list:
Linked List: 10 20 30 
The first list is NOT circular.

Second list:
Linked List: 1 2 3 
The second list is circular.

Q10

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Function to split the circular linked list into two halves
void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    if (head == NULL)
        return;

    struct Node* slow = head;
    struct Node* fast = head;

    // Use slow and fast pointers to find the middle
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even number of nodes, move fast one more step
    if (fast->next->next == head)
        fast = fast->next;

    // Set the heads of the two halves
    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slow->next;

    // Make first half circular
    fast->next = slow->next;
    // Make second half circular
    slow->next = head;
}

// Function to display a circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Create a circular linked list
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);

    printf("Original Circular Linked List:\n");
    display(head);

    // Split the list into two halves
    splitList(head, &head1, &head2);

    printf("\nFirst Half:\n");
    display(head1);

    printf("Second Half:\n");
    display(head2);

    return 0;
}

OUTPUT:
Original Circular Linked List:
Circular Linked List: 10 20 30 40 50 60 

First Half:
Circular Linked List: 10 20 30 
Second Half:
Circular Linked List: 40 50 60 
