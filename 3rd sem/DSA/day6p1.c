#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to represent a Deque
struct Deque {
    char items[MAX];
    int front;
    int rear;
};

// Initialize deque
void initDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is full
int isFull(struct Deque *dq) {
    return (dq->rear == MAX - 1);
}

// Check if deque is empty
int isEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

// Add an element to the front of the deque
void addFront(struct Deque *dq, char x) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        printf("Cannot add to the front!\n");
        return;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = x;
}

// Add an element to the rear of the deque
void addRear(struct Deque *dq, char x) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = x;
}

// Remove an element from the front of the deque
char removeFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return '\0';
    }
    char item = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // Deque becomes empty
    } else {
        dq->front++;
    }
    return item;
}

// Remove an element from the rear of the deque
char removeRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return '\0';
    }
    char item = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;  // Deque becomes empty
    } else {
        dq->rear--;
    }
    return item;
}

// Function to check if a string is a palindrome using deque
int isPalindrome(char str[]) {
    struct Deque dq;
    initDeque(&dq);

    // Add characters to the deque
    for (int i = 0; i < strlen(str); i++) {
        addRear(&dq, str[i]);
    }

    // Check for palindrome by comparing characters from front and rear
    while (dq.front < dq.rear) {
        if (removeFront(&dq) != removeRear(&dq)) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

// Main function
int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}