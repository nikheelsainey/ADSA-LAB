Q1

#include <stdio.h>
struct Complex {
    float real;
    float imag;
};
void swap(struct Complex *c1, struct Complex *c2) {
    struct Complex temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int main() {
    struct Complex num1, num2;

    printf("Enter real and imaginary part of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary part of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    printf("\nBefore swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", num1.real, num1.imag);
    printf("Second complex number: %.2f + %.2fi\n", num2.real, num2.imag);

    swap(&num1, &num2);

    printf("\nAfter swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", num1.real, num1.imag);
    printf("Second complex number: %.2f + %.2fi\n", num2.real, num2.imag);

    return 0;
}

Q2

#include<stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i+1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }

    return 0;
}

Q3

#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int roll;
    char name[50];
    struct Date dob;
};

int main() {
    struct Student s1;

    printf("Enter Roll No: ");
    scanf("%d", &s1.roll);

    printf("Enter Name: ");
    scanf("%s", s1.name);

    printf("Enter Date of Birth (dd mm yyyy): ");
    scanf("%d %d %d", &s1.dob.day, &s1.dob.month, &s1.dob.year);

    printf("\nStudent Details:\n");
    printf("Roll No: %d\nName: %s\nDOB: %02d-%02d-%04d\n", 
            s1.roll, s1.name, s1.dob.day, s1.dob.month, s1.dob.year);

    return 0;
}

Q4

#include<stdio.h>

struct Node {
    int data;
    struct Node * next;
};

int main() {
    struct Node n1, n2;

    n1.data = 10;
    n2.data = 20;

    n1.next = &n2;
    n2.next = NULL;

    printf("First Node: %d\n", n1.data);
    printf("Second Node through first: %d\n", n1.next->data);

    return 0;
}

Q5

#include<stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].marks > s[maxIndex].marks) {
            maxIndex = i;
        }
    }

    printf("\nHighest Marks:\nName: %s, Marks: %d\n", s[maxIndex].name, s[maxIndex].marks);

    return 0;
}

Q6

#include<stdio.h>
#include<string.h>

struct Student {
    int roll;
    char name[50];
};

int main() {
    struct Student s1 = {1, "Nikhil"};
    struct Student s2 = {1, "Nikhil"};

    if (s1.roll == s2.roll && strcmp(s1.name, s2.name) == 0) {
        printf("Both students are same.\n");
    } else {
        printf("Students are different.\n");
    }

    return 0;
}

Q7

#include<stdio.h>

struct Player {
    char name[50];
    int runs;
    int wickets;
};

int main() {
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);

    struct Player team[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of player %d\n", i+1);
        printf("Name: ");
        scanf("%s", team[i].name);
        printf("Runs: ");
        scanf("%d", &team[i].runs);
        printf("Wickets: ");
        scanf("%d", &team[i].wickets);
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (team[i].runs > team[maxIndex].runs) {
            maxIndex = i;
        }
    }

    printf("\nPlayer with highest runs:\n");
    printf("Name: %s, Runs: %d, Wickets: %d\n", 
            team[maxIndex].name, team[maxIndex].runs, team[maxIndex].wickets);

    return 0;
}

Q8

#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[20];
    float marks;
};

int main() {
    int n = 3;

    // Using malloc
    struct student *arr1 = (struct student *) malloc(n * sizeof(struct student));
    // Using calloc
    struct student *arr2 = (struct student *) calloc(n, sizeof(struct student));

    // Print first student's data
    printf("Malloc -> roll: %d, marks: %f\n", arr1[0].roll, arr1[0].marks);
    printf("Calloc -> roll: %d, marks: %f\n", arr2[0].roll, arr2[0].marks);

    free(arr1);
    free(arr2);
    return 0;
}


Q9

#include<stdio.h>
#include<stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int **data;
};

int main() {
    struct Matrix mat;
    printf("Enter rows and columns: ");
    scanf("%d %d", &mat.rows, &mat.cols);

    mat.data = (int**) malloc(mat.rows * sizeof(int*));
    for (int i = 0; i < mat.rows; i++) {
        mat.data[i] = (int*) malloc(mat.cols * sizeof(int));
    }

    printf("Enter elements:\n");
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            scanf("%d", &mat.data[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}

Q10

#include<stdio.h>
#include<stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n, extra;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    struct Student *s = (struct Student*) malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }

    printf("\nEnter number of extra students to add: ");
    scanf("%d", &extra);

    s = (struct Student*) realloc(s, (n+extra) * sizeof(struct Student));

    for (int i = n; i < n+extra; i++) {
        printf("\nEnter details of new student %d\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }

    printf("\nAll Students:\n");
    for (int i = 0; i < n+extra; i++) {
        printf("Name: %s, Marks: %d\n", s[i].name, s[i].marks);
    }

    free(s);
    return 0;
}

