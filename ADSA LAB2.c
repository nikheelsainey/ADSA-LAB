Q1a

#include <stdio.h>

int main() {
    int n, i;
    float sum = 0.0;

    printf("Enter number of days: ");
    scanf("%d", &n);

    float sales[n];

    printf("Enter sales for %d days:\n", n);
    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &sales[i]);
    }

    for (i = 0; i < n; i++) {
        sum += sales[i];
    }

    printf("\nTotal sales = %.2f\n", sum);

    return 0;
}

Q1b

#include <stdio.h>

float sumRecursive(float arr[], int n) {
    if (n == 0) {
        return 0; 
    }
    return arr[n - 1] + sumRecursive(arr, n - 1);  
}

int main() {
    int n, i;
    printf("Enter number of days: ");
    scanf("%d", &n);

    float sales[n];

    printf("Enter sales for %d days:\n", n);
    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &sales[i]);
    }

    float total = sumRecursive(sales, n);

    printf("\nTotal sales = %.2f\n", total);

    return 0;
}

Q2a

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of temperature readings: ");
    scanf("%d", &n);

    float temp[n];

    printf("Enter %d temperature readings:\n", n);
    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &temp[i]);
    }

    float max = temp[0];

    for (i = 1; i < n; i++) {
        if (temp[i] > max) {
            max = temp[i];
        }
    }

    printf("\nMaximum temperature = %.2f\n", max);

    return 0;
}

Q2b

#include <stdio.h>

void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
               
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 7; 
    float temp[n];

    printf("Enter 7 temperature readings:\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &temp[i]);
    }

    bubbleSort(temp, n);

    float max = temp[n - 1];

    printf("\nMaximum temperature = %.2f\n", max);

    return 0;
}

Q3a

#include <stdio.h>
#include <string.h>

int main() {
    char username[100];
    int left, right;
    
    printf("Enter username: ");
    scanf("%s", username);

    left = 0;
    right = strlen(username) - 1;

    while (left < right) {
        char temp = username[left];
        username[left] = username[right];
        username[right] = temp;

        left++;
        right--;
    }

    printf("Reversed username: %s\n", username);

    return 0;
}

Q3b

#include <stdio.h>
#include <string.h>

int main() {
    char username[100];
    char reversed[100];
    int length, i;

    printf("Enter username: ");
    scanf("%s", username);

    length = strlen(username);

    for (i = 0; i < length; i++) {
        reversed[i] = username[length - 1 - i];
    }
    reversed[length] = '\0'; 
    printf("Reversed username: %s\n", reversed);

    return 0;
}

Q4a

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("\nResults:\n");
    for (i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d is Even\n", numbers[i]);
        } else {
            printf("%d is Odd\n", numbers[i]);
        }
    }

    return 0;
}

Q4b

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("\nResults:\n");
    for (i = 0; i < n; i++) {
        if (numbers[i] & 1) {
            printf("%d is Odd\n", numbers[i]);
        } else {
            printf("%d is Even\n", numbers[i]);
        }
    }

    return 0;
}

Q5a

#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1; 
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    printf("Factorial of %d = %llu\n", n, factorial);

    return 0;
}

Q5b

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  
    }
    return n * factorial(n - 1);  
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    unsigned long long result = factorial(n);

    printf("Factorial of %d = %llu\n", n, result);

    return 0;
}

Q6a

#include <stdio.h>

int main() {
    int n, i, key, found = 0;

    printf("Enter number of customer IDs: ");
    scanf("%d", &n);

    int ids[n];

    printf("Enter %d customer IDs:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ids[i]);
    }

    printf("Enter customer ID to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (ids[i] == key) {
            printf("Customer ID %d found at position %d (index %d).\n", key, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Customer ID %d not found in the dataset.\n", key);
    }

    return 0;
}

Q6b

#include <stdio.h>

int main() {
    int n, key, i;

    printf("Enter number of customer IDs: ");
    scanf("%d", &n);

    int ids[n + 1];
    printf("Enter %d customer IDs:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ids[i]);
    }

    printf("Enter customer ID to search: ");
    scanf("%d", &key);

    ids[n] = key;

    i = 0;
    while (ids[i] != key) {
        i++;
    }

    if (i < n) {
        printf("Customer ID %d found at position %d (index %d).\n", key, i + 1, i);
    } else {
        printf("Customer ID %d not found in the dataset.\n", key);
    }

    return 0;
}

Q7a

#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    printf("First %d natural numbers:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

Q7b

#include <stdio.h>

void printNumbers(int current, int n) {
    if (current > n) {
        return; 
    }
    printf("%d ", current);
    printNumbers(current + 1, n); 
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 0;
    }

    printf("First %d natural numbers:\n", n);
    printNumbers(1, n);
    printf("\n");

    return 0;
}

Q8a

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char comment[200];
    int count = 0;

    printf("Enter a comment: ");
    fgets(comment, sizeof(comment), stdin);

    for (int i = 0; comment[i] != '\0'; i++) {
        char ch = tolower(comment[i]);  
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    printf("Number of vowels: %d\n", count);

    return 0;
}

Q8b

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char comment[200];
    int count = 0;

    int isVowel[256] = {0};
    isVowel['a'] = isVowel['A'] = 1;
    isVowel['e'] = isVowel['E'] = 1;
    isVowel['i'] = isVowel['I'] = 1;
    isVowel['o'] = isVowel['O'] = 1;
    isVowel['u'] = isVowel['U'] = 1;

    printf("Enter a comment: ");
    fgets(comment, sizeof(comment), stdin);

    for (int i = 0; comment[i] != '\0'; i++) {
        if (isVowel[(unsigned char)comment[i]]) {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);

    return 0;
}

Q9a

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);

    a = a + b;  
    b = a - b;  
    a = a - b;  

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

Q9b

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);

    a = a ^ b; 
    b = a ^ b; 
    a = a ^ b; 
    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

Q10a

#include <stdio.h>
#include <string.h>

int main() {
    char numStr[50];

    printf("Enter the ID number: ");
    scanf("%s", numStr);

    int left = 0;
    int right = strlen(numStr) - 1;
    int isPalindrome = 1;
    while (left < right) {
        if (numStr[left] != numStr[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("The ID %s is a palindrome.\n", numStr);
    } else {
        printf("The ID %s is not a palindrome.\n", numStr);
    }

    return 0;
}

Q10b

#include <stdio.h>

int main() {
    int num, original, reversed = 0, digit;

    printf("Enter the ID number: ");
    scanf("%d", &num);

    original = num;

    while (num > 0) {
        digit = num % 10;        
        reversed = reversed * 10 + digit; 
        num /= 10;                
    }

    if (original == reversed) {
        printf("The ID %d is a palindrome.\n", original);
    } else {
        printf("The ID %d is not a palindrome.\n", original);
    }

    return 0;
}


