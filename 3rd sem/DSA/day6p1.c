#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Initialize deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Add character to the front
void addFront(struct Deque* deque, char data) {
    struct Node* newNode = createNode(data);
    if (!deque->front) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    printf("Added %c to the front.\n", data);
}

// Add character to the rear
void addRear(struct Deque* deque, char data) {
    struct Node* newNode = createNode(data);
    if (!deque->rear) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    printf("Added %c to the rear.\n", data);
}

// Remove character from the front
char removeFront(struct Deque* deque) {
    if (!deque->front) return '\0';
    struct Node* temp = deque->front;
    char data = temp->data;
    deque->front = deque->front->next;
    if (deque->front) deque->front->prev = NULL;
    else deque->rear = NULL;
    free(temp);
    return data;
}

// Remove character from the rear
char removeRear(struct Deque* deque) {
    if (!deque->rear) return '\0';
    struct Node* temp = deque->rear;
    char data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear) deque->rear->next = NULL;
    else deque->front = NULL;
    free(temp);
    return data;
}

// Display the contents of the deque
void display(struct Deque* deque) {
    if (!deque->front) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* current = deque->front;
    printf("Deque contents: ");
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Check if the deque forms a palindrome
int isPalindrome(struct Deque* deque) {
    struct Node* left = deque->front;
    struct Node* right = deque->rear;
    while (left && right && left != right && left->prev != right) {
        if (left->data != right->data) {
            return 0;  // Not a palindrome
        }
        left = left->next;
        right = right->prev;
    }
    return 1;  // Is a palindrome
}

// Menu-driven program
int main() {
    struct Deque* deque = createDeque();
    int choice;
    char element;

    do {
        printf("\nMenu:\n");
        printf("1. Add Front\n");
        printf("2. Add Rear\n");
        printf("3. Remove Front\n");
        printf("4. Remove Rear\n");
        printf("5. Display\n");
        printf("6. Check Palindrome\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to add at front: ");
                scanf(" %c", &element);
                addFront(deque, element);
                break;
            case 2:
                printf("Enter character to add at rear: ");
                scanf(" %c", &element);
                addRear(deque, element);
                break;
            case 3:
                element = removeFront(deque);
                if (element != '\0') {
                    printf("Removed %c from the front.\n", element);
                } else {
                    printf("Deque is empty!\n");
                }
                break;
            case 4:
                element = removeRear(deque);
                if (element != '\0') {
                    printf("Removed %c from the rear.\n", element);
                } else {
                    printf("Deque is empty!\n");
                }
                break;
            case 5:
                display(deque);
                break;
            case 6:
                if (isPalindrome(deque)) {
                    printf("The deque forms a palindrome.\n");
                } else {
                    printf("The deque does not form a palindrome.\n");
                }
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}