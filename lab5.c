Q1

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(struct Node* head) {
    for (; head; head = head->next)
        printf("%d -> ", head->data);
    printf("NULL\n");
}

// Iterative reverse
struct Node* reverseIter(struct Node* head) {
    struct Node *prev = NULL, *next;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Recursive reverse
struct Node* reverseRec(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* rest = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    printf("Original: ");
    printList(head);

    head = reverseIter(head);
    printf("Iterative: ");
    printList(head);

    head = reverseRec(head);
    printf("Recursive: ");
    printList(head);

    return 0;
}

Output:

Original: 1 -> 2 -> 3 -> 4 -> NULL
Iterative: 4 -> 3 -> 2 -> 1 -> NULL
Recursive: 1 -> 2 -> 3 -> 4 -> NULL

Q2

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Iterative method to reverse the linked list
struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse the current node's pointer
        prev = curr;         // Move prev forward
        curr = next;         // Move curr forward
    }
    return prev; // New head
}

// Recursive method to reverse the linked list
struct Node* reverseRecursive(struct Node* head) {
    // Base case: empty list or last node
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Driver code
int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original list:\n");
    printList(head);

    // Reverse iteratively
    head = reverseIterative(head);
    printf("\nReversed list (Iterative):\n");
    printList(head);

    // Reverse recursively (to restore original order)
    head = reverseRecursive(head);
    printf("\nReversed list (Recursive):\n");
    printList(head);

    return 0;
}

Output:

Original list:
1 -> 2 -> 3 -> 4 -> NULL

Reversed list (Iterative):
4 -> 3 -> 2 -> 1 -> NULL

Reversed list (Recursive):
1 -> 2 -> 3 -> 4 -> NULL

Q3

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to display the linked list
void display(struct Node* head) {
    printf("Linked list elements: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *temp = NULL, *tail = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        temp = newNode(val);

        if (head == NULL)
            head = temp;  // first node
        else
            tail->next = temp;  // link new node

        tail = temp;  // move tail
    }

    display(head);
    return 0;
}

Output:

Enter number of nodes: 5
Enter data for node 1: 2
Enter data for node 2: 4
Enter data for node 3: 5
Enter data for node 4: 8
Enter data for node 5: 9
Linked list elements: 2 -> 4 -> 5 -> 8 -> 9 -> NULL

Q4

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

int hasLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;  // Loop found
    }
    return 0;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    // Create a loop for testing
    head->next->next->next->next = head->next;

    if (hasLoop(head))
        printf("Loop detected!\n");
    else
        printf("No loop.\n");

    return 0;
}

Output:

Loop detected!

Q5

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(struct Node* head) {
    printf("List: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* n = newNode(data);
    n->next = *head;
    *head = n;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* n = newNode(data);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

void insertAtPosition(struct Node** head, int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* n = newNode(data);
    struct Node* temp = *head;
    for (int i = 1; temp && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(n);
        return;
    }
    n->next = temp->next;
    temp->next = n;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    insertAtBeginning(&head, 5);
    printList(head);

    insertAtPosition(&head, 15, 3);
    printList(head);

    return 0;
}

Output:

List: 10 -> 20 -> 30 -> NULL
List: 5 -> 10 -> 20 -> 30 -> NULL
List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

Q6

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to display the list
void display(struct Node* head) {
    printf("Linked list: ");
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);

    display(head);

    int total = countNodes(head);
    printf("Total number of nodes: %d\n", total);

    return 0;
}

Output:

Linked list: 10 -> 20 -> 30 -> 40 -> NULL
Total number of nodes: 4

Q7

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    return n;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }

    return result;
}

int main() {
    // First sorted list: 1 -> 3 -> 5
    struct Node* l1 = newNode(1);
    l1->next = newNode(3);
    l1->next->next = newNode(5);

    // Second sorted list: 2 -> 4 -> 6
    struct Node* l2 = newNode(2);
    l2->next = newNode(4);
    l2->next->next = newNode(6);

    printf("List 1: ");
    printList(l1);

    printf("List 2: ");
    printList(l2);

    struct Node* merged = mergeLists(l1, l2);

    printf("Merged Sorted List: ");
    printList(merged);

    return 0;
}

Output:

List 1: 1 -> 3 -> 5 -> NULL
List 2: 2 -> 4 -> 6 -> NULL
Merged Sorted List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL


Q8

#include <stdio.h>
#include <stdlib.h>
// Define node structure
struct Node {
 int data;
 struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}// Function to display linked list
void displayList(struct Node* head) {
 struct Node* temp = head;
 printf("Linked List: ");
 while (temp != NULL) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\n");
}
// Delete from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 struct Node* temp = head;
 head = head->next;
 free(temp);
 return head;
}
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 if (head->next == NULL) {
 free(head);
 return NULL;
 }
 struct Node* temp = head;
 while (temp->next->next != NULL) {
 temp = temp->next;
 }
 free(temp->next);
 temp->next = NULL;
 return head;
}// Delete from a given position (1-based index)
struct Node* deleteFromPosition(struct Node* head, int pos) {
 if (head == NULL) {
 printf("List is empty.\n");
 return head;
 }
 if (pos == 1) {
 struct Node* temp = head;
 head = head->next;
 free(temp);
 return head;
 }
 struct Node* temp = head;
 for (int i = 1; i < pos - 1 && temp != NULL; i++) {
 temp = temp->next;
 }
 if (temp == NULL || temp->next == NULL) {
 printf("Position out of range.\n");
 return head;
 }
 struct Node* nodeToDelete = temp->next;
 temp->next = nodeToDelete->next;
 free(nodeToDelete);
 return head;
}
int main() {
 // Create a sample linked list: 10 -> 20 -> 30 -> 40 -> 50
 struct Node* head = createNode(10);
 head->next = createNode(20);
 head->next->next = createNode(30);
 head->next->next->next = createNode(40);
 head->next->next->next->next = createNode(50);
 printf("Original Linked List:\n");
 displayList(head);
 // Delete from beginning
 head = deleteFromBeginning(head);
 printf("After deleting from beginning:\n");
 displayList(head);
 // Delete from end
 head = deleteFromEnd(head);
 printf("After deleting from end:\n");
 displayList(head);
 // Delete from a given position
 int pos;
 printf("Enter position to delete node: ");
 scanf("%d", &pos);
 head = deleteFromPosition(head, pos);
 printf("After deleting node from position %d:\n", pos);
 displayList(head);
 return 0;}
 
 Output:
 
 Original Linked List:
Linked List: 10 20 30 40 50 
After deleting from beginning:
Linked List: 20 30 40 50 
After deleting from end:
Linked List: 20 30 40 
Enter position to delete node: 3
After deleting node from position 3:
Linked List: 20 30 

Q9

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = d; n->next = NULL; return n;
}

void printMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    if (!head) { printf("List is empty\n"); return; }
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    head->next->next->next->next = newNode(50);

    printMiddle(head);
    return 0;
}

Output:

Middle element: 30

Q10

#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int d) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = d; n->next = NULL; return n;
}

void removeDuplicates(struct Node* head) {
    struct Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            struct Node* dup = curr->next;
            curr->next = curr->next->next;
            free(dup);
        } else curr = curr->next;
    }
}

void printList(struct Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(20);
    head->next->next->next = newNode(30);
    head->next->next->next->next = newNode(30);

    printf("Original list:\n");
    printList(head);

    removeDuplicates(head);

    printf("After removing duplicates:\n");
    printList(head);

    return 0;
}

Output:

Original list:
10 -> 20 -> 20 -> 30 -> 30 -> NULL
After removing duplicates:
10 -> 20 -> 30 -> NULL
