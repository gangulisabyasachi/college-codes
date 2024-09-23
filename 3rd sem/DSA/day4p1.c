#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int top;
    int items[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;  // Initialize top of stack to -1 (indicating empty stack)
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
    printf("Pushed %d\n", item);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate an error
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;  // Return -1 to indicate an error
    }
    return s->items[s->top];
}

void display(Stack *s) {
    int i;
	if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    for (i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}
int main() {
    Stack s;
    int choice, item;
    initStack(&s);

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                item = pop(&s);
                if (item != -1) {
                    printf("Popped item: %d\n", item);
                }
                break;
            case 3:
                item = peek(&s);
                if (item != -1) {
                    printf("Top item: %d\n", item);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// output


// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 34
// Pushed 34

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 765
// Pushed 765

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 45
// Pushed 45

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 7896
// Pushed 7896

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 345
// Pushed 345

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 1
// Pushed 1

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 1
// Pushed 1

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 1
// Pushed 1

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 1
// Pushed 1

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 1
// Pushed 1

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 
// 1
// Enter the item to push: 3564
// Pushed 3564

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 1
// Enter the item to push: 345
// Pushed 345

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 4
// Stack contents:
// 345
// 3564
// 1
// 1
// 1
// 1
// 1
// 345
// 7896
// 45
// 765
// 34

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 2
// Popped item: 345

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 3
// Top item: 3564

// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter your choice (1-5): 5
// Exiting...
