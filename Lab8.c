 Q1

#include <stdio.h>

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {29, 10, 14, 37, 13};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("Iteration %d: ", i);
        print(a, n);
    }
}

OUTPUT:
Iteration 0: 10 29 14 37 13 
Iteration 1: 10 13 14 37 29 
Iteration 2: 10 13 14 37 29 
Iteration 3: 10 13 14 29 37 

Q2

#include <stdio.h>

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {20, 5, 8, 15, 2};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("Iteration %d: ", i);
        print(a, n);
    }
}

OUTPUT:
Iteration 0: 2 5 8 15 20 
Iteration 1: 2 5 8 15 20 
Iteration 2: 2 5 8 15 20 
Iteration 3: 2 5 8 15 20

Q3

#include <stdio.h>

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {7, 4, 9, 1, 3, 6};
    int n = 6;
    int k = 3;

    for (int i = 0; i < k; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min]) min = j;

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        printf("Iteration %d: ", i);
        print(a, n);
    }
}

OUTPUT:
Iteration 0: 1 4 9 7 3 6 
Iteration 1: 1 3 9 7 4 6 
Iteration 2: 1 3 4 7 9 6 

Q4

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int x) {
    Node* t = malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;
    return t;
}

void print(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void selectionSort(Node **head) {
    Node *i = *head;

    while (i && i->next) {
        Node *min = i;
        Node *j = i->next;

        while (j) {
            if (j->data < min->data)
                min = j;
            j = j->next;
        }

        int temp = i->data;
        i->data = min->data;
        min->data = temp;

        print(*head);
        i = i->next;
    }
}

int main() {
    Node *head = newNode(5);
    head->next = newNode(3);
    head->next->next = newNode(8);
    head->next->next->next = newNode(1);

    selectionSort(&head);
}

OUTPUT:
1 3 8 5 
1 3 8 5 
1 3 5 8

Q5

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int x) {
    Node* t = malloc(sizeof(Node));
    t->data = x;
    t->next = NULL;
    return t;
}

Node* merge(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

void print(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node *a = newNode(1);
    a->next = newNode(3);
    a->next->next = newNode(5);

    Node *b = newNode(2);
    b->next = newNode(4);
    b->next->next = newNode(6);

    Node *m = merge(a, b);
    print(m);
}

OUTPUT:
1 2 3 4 5 6 

Q6

#include <stdio.h>
#include <stdlib.h>

typedef struct Q {
    int data;
    struct Q *next;
} Q;

typedef struct {
    Q *front, *rear;
} Queue;

Queue* create() {
    Queue *q = malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue *q, int x) {
    Q *n = malloc(sizeof(Q));
    n->data = x;
    n->next = NULL;

    if (!q->rear)
        q->front = q->rear = n;
    else {
        q->rear->next = n;
        q->rear = n;
    }
}

int dequeue(Queue *q) {
    Q *t = q->front;
    int x = t->data;
    q->front = t->next;
    if (!q->front) q->rear = NULL;
    free(t);
    return x;
}

int front(Queue *q) { return q->front->data; }
int empty(Queue *q) { return q->front == NULL; }

Queue* mergeQ(Queue *a, Queue *b) {
    Queue *r = create();
    while (!empty(a) && !empty(b)) {
        if (front(a) < front(b)) enqueue(r, dequeue(a));
        else enqueue(r, dequeue(b));
    }
    while (!empty(a)) enqueue(r, dequeue(a));
    while (!empty(b)) enqueue(r, dequeue(b));
    return r;
}

void print(Queue *q) {
    Q *t = q->front;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    Queue *a = create();
    Queue *b = create();

    enqueue(a, 1); enqueue(a, 4); enqueue(a, 7);
    enqueue(b, 2); enqueue(b, 3); enqueue(b, 6);

    Queue *m = mergeQ(a, b);
    print(m);
}

OUTPUT:
1 2 3 4 6 7 

Q7

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int l, int r) {
    for (int i = l; i < r; i++) {
        int min = i;
        for (int j = i + 1; j <= r; j++)
            if (a[j] < a[min]) min = j;

        int t = a[i]; a[i] = a[min]; a[min] = t;
    }
}

void merge(int a[], int l, int m, int r) {
    int i = l, j = m+1, k = 0;
    int *temp = malloc((r-l+1)*sizeof(int));

    while (i <= m && j <= r)
        temp[k++] = (a[i] < a[j] ? a[i++] : a[j++]);

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (i = 0; i < k; i++) a[l+i] = temp[i];
    free(temp);
}

int main() {
    int a[] = {9, 5, 1, 8, 3, 7, 2, 6};
    int n = 8, chunk = 4;

    for (int i = 0; i < n; i += chunk)
        selectionSort(a, i, (i+chunk-1 < n ? i+chunk-1 : n-1));

    merge(a, 0, chunk-1, n-1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

OUTPUT:
1 2 3 5 6 7 8 9 

Q8

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a[100];
    int top;
} Stack;

void push(Stack *s, int x) { s->a[++s->top] = x; }
int pop(Stack *s) { return s->a[s->top--]; }
int peek(Stack *s) { return s->a[s->top]; }
int empty(Stack *s) { return s->top == -1; }

int main() {
    int A[] = {1, 4, 6};
    int B[] = {2, 3, 5};
    int n = 3, m = 3;

    Stack sA = {.top=-1}, sB = {.top=-1}, R = {.top=-1};

    for (int i = 0; i < n; i++) push(&sA, A[i]);
    for (int i = 0; i < m; i++) push(&sB, B[i]);

    while (!empty(&sA) && !empty(&sB)) {
        if (peek(&sA) >= peek(&sB))
            push(&R, pop(&sA));
        else
            push(&R, pop(&sB));
    }

    while (!empty(&sA)) push(&R, pop(&sA));
    while (!empty(&sB)) push(&R, pop(&sB));

    while (!empty(&R))
        printf("%d ", pop(&R));
}

OUTPUT:
1 2 3 4 5 6 
