Q1
#include <stdio.h>

int main(){
    printf("Hello, World!/n");
    return 0;
}

Q2
#include <stdio.h>

int main() {
    int a, b, temp;
    
    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("\nBefore swapping: a = %d, b = %d\n", a, b);
    
    //swapping using a temporary variable
    temp = a;
    a = b;
    b = temp;
    
    printf("After Swapping: a = %d, b = %d\n", a, b);
    return 0;
}

Q3
#include <stdio.h>

int main() {
    int token;
    
    //Input token number
    printf("Enter customer token number:");
scanf("%d, &token");

//check even or odd
if (token % 2 == 0) {
//     printf("Token %d is EVEN.\n", token);
// } else {
//     printf("Token %d is ODD.\n", token);
// }
// return 0;
// }

Q4
#include <stdio.h>

int main() {
    int a, b, c;
    
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    if (a >= b && a >= c) {
        printf("%d is the largest number.\n", a);
    }
    else if (b >= a && b >= c) {
        printf("%d is the largest number.\n", b);
    }
    else {
        printf("%d is the largest number.\n", c);
    }
    return 0;
}
    
Q5 
#include <stdio.h>
int main() {
    char op;
    float num1, num2;
    
    printf("Enter an operator(+, -, *, /): ");
    scanf(" %c", &op);
    
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    switch (op) {
        case '+':
        printf("%f + %f = %f\n", num1, num2, num1 + num2);
        break;
    
        case '-':
        printf("%f + %f = %f\n", num1, num2, num1 - num2);
        break;
        
        case '*':
        printf("%f + %f = %f\n", num1, num2, num1 * num2);
        break;
        
        case '/':
        if (num2 != 0)
        printf("%f + %f = %f\n", num1, num2, num1 / num2);
        else
        printf("Error! Division by zero is not allowed.\n");
        break;
        
        default:
        printf("Error! Operator is not correct.\n");
    }
    return 0;
}

Q6

#include <stdio.h>
int main() {
    int n;
    unsigned long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %llu\n", n, fact);
    }
    return 0;
}

Q7

#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci series (first %d terms):\n", n); 
        
        for(int i = 1; i <= n; i++) {
            printf("%d", first);
            next = first + second;
            first = second;
            second = next;
        }
        printf("\n");
    }
    
    return 0;
}

Q8

#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
}

printf("Reversed number = %d\n", reversed);

return 0;
}

Q9

#include <stdio.h>

int main() {
    int pin, original, reversed = 0, remainder;

    printf("Enter your PIN: ");
    scanf("%d", &pin);

    original = pin;  // store the original PIN

    // Reverse the number
    while (pin != 0) {
        remainder = pin % 10;
        reversed = reversed * 10 + remainder;
        pin /= 10;
    }

    // Check palindrome
    if (original == reversed) {
        printf(" Y PIN Accepted: It is a Palindrome.\n");
    } else {
        printf(" N PIN Rejected: Not a Palindrome.\n");
    }

    return 0;
}

Q10

#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle zero separately
    if (num == 0) {
        count = 1;
    } else {
        // If negative, make it positive
        if (num < 0) {
            num = -num;
        }

        while (num != 0) {
            num /= 10;   // remove last digit
            count++;
        }
    }

    printf("Number of digits = %d\n", count);

    return 0;
}

Q11

#include <stdio.h>

int main() {
    int num, sum = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    while (num != 0) {
        remainder = num % 10;   
        sum += remainder;      
        num /= 10;              
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}

Q12

#include <stdio.h>

int main() {
    int num, i, isPrime = 1; 

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0; 
        for (i = 2; i * i <= num; i++) {   
            
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("%d is a Prime Number.\n", num);
    else
        printf("%d is NOT a Prime Number.\n", num);

    return 0;
}

Q13

#include <stdio.h>

int main() {
    int n, i, max;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Maximum element in the array = %d\n", max);

    return 0;
}


Q14

#include <stdio.h>
#include <string.h>
#include <ctype.h>  

int main() {
    char str[100];
    int i, count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); 

    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);   
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    printf("Number of vowels = %d\n", count);

    return 0;
}

Q15

#include <stdio.h>

int main() {
    int units;
    float bill = 0;

    printf("Enter electricity units consumed: ");
    scanf("%d", &units);

    if (units <= 100) {
        bill = units * 5;
    } 
    else if (units <= 200) {
        bill = (100 * 5) + (units - 100) * 7;
    } 
    else {
        bill = (100 * 5) + (100 * 7) + (units - 200) * 10;
    }

    printf("Electricity Bill = ₹%.2f\n", bill);

    return 0;
}

Q16

#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1)  
        return 1;
    else
        return n * factorial(n - 1); 
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
    } else {
        printf("Factorial of %d = %lld\n", num, factorial(num));
    }

    return 0;
}

Q17

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series (first %d terms):\n", n);
        for (i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}


Q18

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;          
    else
        return gcd(b, a % b); 
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0) num1 = -num1; 
    if (num2 < 0) num2 = -num2;

    printf("GCD of %d and %d = %d\n", num1, num2, gcd(num1, num2));

    return 0;
}

Q19

#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0)
        return 0;               
    else
        return (n % 10) + sumOfDigits(n / 10); 
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;  
    }

    printf("Sum of digits = %d\n", sumOfDigits(num));

    return 0;
}


Q20


#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;   
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key); 
    else
        return binarySearch(arr, mid + 1, high, key); 
}

int main() {
    int n, key, i, result;

    printf("Enter number of books (array size): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d book IDs (sorted):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter book ID to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Book ID %d not found.\n", key);
    else
        printf("Book ID %d found at position %d (index %d).\n", key, result + 1, result);

    return 0;
}




