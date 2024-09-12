// Implement a Singly Linked List of integers.

// 1. addFront(x): Add an element x to the front of a singly linked list.
// 2. addEnd(x): Add an element x to the end of a singly linked list.
// 3. addPos(i,x): Add an element x at the i-h position of a singly linked list
// 4. delPos(i): Remove the i-th element from a singly linked list.
// 5. delFront(): Remove the element at the start of a singly linked list
// 6. delEnd(): Remove the element at the end of a singly linked list
// 7. delOne(x): Remove one occurrence of x from a singly linked list
// 8. delAll(x): Remove all occurrences of x from a singly linked list
// 9. retFront(i): Return the i-th element from the start of a singly linked list
// 10. retEnd(i):: Return the i-th element from the start of a singly linked list  
// 11. retMid():- Return the middle  element of a list for even no of element return the left one.
// 12. delMid():- Delete the mid element of a list for even no of element return the left one.
// 13. delEndPos():- Delete the i th element  from the end. 

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Add an element to the front of the list
void addFront(struct Node** head, int x) {
    struct Node* newNode = createNode(x);
    newNode->next = *head;
    *head = newNode;
}

// Add an element to the end of the list
void addEnd(struct Node** head, int x) {
    struct Node* newNode = createNode(x);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Add an element at the i-th position of the list
void addPos(struct Node** head, int i, int x) {
    if (i == 0) {
        addFront(head, x);
        return;
    }
    struct Node* newNode = createNode(x);
    struct Node* temp = *head;
    for (int j = 0; j < i - 1 && temp != NULL; j++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove the i-th element from the list
void delPos(struct Node** head, int i) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (i == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int j = 0; j < i - 1 && temp->next != NULL; j++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Remove the element at the start of the list
void delFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Remove the element at the end of the list
void delEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Remove one occurrence of x from the list
void delOne(struct Node** head, int x) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Remove all occurrences of x from the list
void delAll(struct Node** head, int x) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == x) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Return the i-th element from the start of the list
int retFront(struct Node* head, int i) {
    struct Node* temp = head;
    for (int j = 0; j < i && temp != NULL; j++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return -1;
    }
    return temp->data;
}

// Return the i-th element from the end of the list
int retEnd(struct Node* head, int i) {
    struct Node* fast = head;
    struct Node* slow = head;
    for (int j = 0; j < i; j++) {
        if (fast == NULL) {
            printf("Position out of bounds\n");
            return -1;
        }
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

// Return the middle element of the list
int retMid(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

// Delete the middle element of the list
void delMid(struct Node** head) {
    struct Node* fast = *head;
    struct Node* slow = *head;
    struct Node* prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev != NULL) {
        prev->next = slow->next;
    } else {
        *head = slow->next;
    }
    free(slow);
}

// Delete the i-th element from the end
void delEndPos(struct Node** head, int i) {
    int index = retEnd(*head, i);
    delPos(head, index);
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, x, i;

    do {
        printf("\nMenu:\n");
        printf("1. Add to front\n");
        printf("2. Add to end\n");
        printf("3. Add at position\n");
        printf("4. Delete from position\n");
        printf("5. Delete from front\n");
        printf("6. Delete from end\n");
        printf("7. Delete one occurrence\n");
        printf("8. Delete all occurrences\n");
        printf("9. Return i-th element from start\n");
        printf("10. Return i-th element from end\n");
        printf("11. Return middle element\n");
        printf("12. Delete middle element\n");
        printf("13. Delete i-th element from end\n");
        printf("14. Print list\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add to front: ");
                scanf("%d", &x);
                addFront(&head, x);
                break;
            case 2:
                printf("Enter element to add to end: ");
                scanf("%d", &x);
                addEnd(&head, x);
                break;
            case 3:
                printf("Enter position and element: ");
                scanf("%d %d", &i, &x);
                addPos(&head, i, x);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &i);
                delPos(&head, i);
                break;
            case 5:
                delFront(&head);
                break;
            case 6:
                delEnd(&head);
                break;
            case 7:
                printf("Enter element to delete one occurrence: ");
                scanf("%d", &x);
                delOne(&head, x);
                break;
            case 8:
                printf("Enter element to delete all occurrences: ");
                scanf("%d", &x);
                delAll(&head, x);
                break;
            case 9:
                printf("Enter position to return element: ");
                scanf("%d", &i);
                x = retFront(head, i);
                if (x != -1) {
                    printf("Element at position %d: %d\n", i, x);
                }
                break;
            case 10:
                printf("Enter position to return element from end: ");
                scanf("%d", &i);
                x = retEnd(head, i);
                if (x != -1) {
                    printf("Element at position %d from end: %d\n", i, x);
                }
                break;
            case 11:
                x = retMid(head);
                printf("Middle element: %d\n", x);
                break;
            case 12:
                delMid(&head);
                break;
            case 13:
                printf("Enter position to delete from end: ");
                scanf("%d", &i);
                delEndPos(&head, i);
                break;
            case 14:
                printList(head);
                break;
            case 15:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 15);

    return 0;
}
