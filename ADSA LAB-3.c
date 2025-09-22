1

#include <stdio.h>
#include <limits.h>

int main() {
    // Predefined array
    int arr[] = {11, 44, 77, 55, 33, 99, 88, 22};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    if (second == INT_MIN) {
        printf("No second largest element (all elements are equal).\n");
    } else {
        printf("The second largest element is: %d\n", second);
    }

    return 0;
}

2

#include <stdio.h>

int main() {
    // ✅ Predefined array and target sum
    int arr[] = {5, 8, 3, 2, 7, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int S = 15;  // Target sum

    int start = 0, current_sum = arr[0];
    int found = 0;

    for (int end = 1; end <= n; end++) {
        // Shrink the window while current_sum exceeds S
        while (current_sum > S && start < end - 1) {
            current_sum -= arr[start];
            start++;
        }

        // Check if we found the sum
        if (current_sum == S) {
            printf("Subarray with sum %d found from index %d to %d\n", S, start, end - 1);
            found = 1;
            break;
        }

        // Add next element to current_sum
        if (end < n) {
            current_sum += arr[end];
        }
    }

    if (!found) {
        printf("No subarray with sum %d exists.\n", S);
    }

    return 0;
}

3

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int k) {
    k = k % n; 
    if (k == 0) return;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;  
    
    rotateRight(arr, n, k);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

4

#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    struct Student students[] = {
        {"Nikhil", 101, 98.5},
        {"Paras", 102, 92.0},
        {"Sahil", 103, 76.4},
        {"Manish", 104, 92.0}, 
        {"Arjun", 105, 85.7}
    };
    int n = sizeof(students) / sizeof(students[0]);

    int topIndex = 0;

    for (int i = 1; i < n; i++) {
        if (students[i].marks > students[topIndex].marks) {
            topIndex = i;
        }
    }

    printf("Student with highest marks:\n");
    printf("Name: %s\n", students[topIndex].name);
    printf("Roll Number: %d\n", students[topIndex].rollNumber);
    printf("Marks: %.2f\n", students[topIndex].marks);

    return 0;
}


5

#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[20];
};

int main() {
    struct Employee employees[] = {
        {101, "Nikhil", 50000, "HR"},
        {102, "Paras", 60000, "IT"},
        {103, "Sahil", 55000, "Finance"},
        {104, "Manish", 65000, "IT"},
        {105, "Arjun", 52000, "Marketing"}
    };

    int n = sizeof(employees) / sizeof(employees[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].department, "IT") == 0) {
            employees[i].salary *= 1.10; 
        }
    }
    printf("Updated Employee Details:\n");
    printf("ID\tName\t\tSalary\t\tDepartment\n");
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%.2f\t%s\n",
              employees[i].id,
              employees[i].name,
              employees[i].salary,
              employees[i].department);
    }

    return 0;
}

6

#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book books[] = {
        {"The Alchemist", "Paulo Coelho", 450.0},
        {"C Programming", "Dennis Ritchie", 299.5},
        {"Clean Code", "Robert C. Martin", 550.0},
        {"The Pragmatic Programmer", "Andrew Hunt", 700.0},
        {"Think Like a Monk", "Jay Shetty", 399.0}
    };

    int n = sizeof(books) / sizeof(books[0]);
    float limit = 400.0; 

    printf("Books with price above %.2f:\n", limit);
    printf("---------------------------------------------\n");
    printf("%-25s %-20s %-7s\n", "Title", "Author", "Price");
    printf("---------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (books[i].price > limit) {
            printf("%-25s %-20s %.2f\n",
                  books[i].title,
                  books[i].author,
                  books[i].price);
        }
    }

    return 0;
}

7

#include <stdio.h>

struct Date { int day, month, year; };

int main() {
    struct Date d1 = {22, 9, 2025}, d2 = {15, 8, 2025};

    if (d1.year < d2.year || 
      (d1.year == d2.year && d1.month < d2.month) || 
      (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day))
        printf("Earlier date: %02d-%02d-%04d\n", d1.day, d1.month, d1.year);
    else if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        printf("Both dates are the same: %02d-%02d-%04d\n", d1.day, d1.month, d1.year);
    else
        printf("Earlier date: %02d-%02d-%04d\n", d2.day, d2.month, d2.year);

    return 0;
}

8

#include <stdio.h>

int main() {
    int nums[] = {2, 7, 11, 15}, n = 4, target = 9;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Indices: %d and %d\n", i, j);
                return 0;
            }
        }
    }
    return 0;
}

9

#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char strs[][20], int n) {
    static char prefix[20];
    strcpy(prefix, strs[0]);
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) j++;
        prefix[j] = '\0';
        if (!prefix[0]) return "";
    }
    return prefix;
}

int main() {
    char strs[][20] = {"flower", "flow", "flight"};
    int n = sizeof(strs) / sizeof(strs[0]);
    printf("Longest Common Prefix: \"%s\"\n", longestCommonPrefix(strs, n));
    return 0;
}

10

#include <stdio.h>

int main() {
    int nums[] = {1, 2, 3, 4, 2}, n = 5;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (nums[i] == nums[j]) {
                printf("true\n");
                return 0;
            }

    printf("false\n");
    return 0;
}
