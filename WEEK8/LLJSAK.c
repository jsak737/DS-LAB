#include <stdio.h>
#include <stdlib.h>

void push();
int pop();

void insert();
int delet();

void display();

struct Node {
    int data;
    struct Node *link;
};

typedef struct Node node;
node *start = NULL;
node *curr, *temp, *new1;

int main() {
    while (1) {
        printf("1. STACK \n2. QUEUE\n3. EXIT\n");
        printf("Make your choice:\n");
        int ch;
        scanf("%d", &ch);

        switch (ch) {
            case 1: { clearList();
                while (1) {
                    printf("Linked list is being implemented as stack!\n1.PUSH \n2.POP\n3.DISPLAY \n4.EXIT\n");
                    int ch1;
                    scanf("%d", &ch1);
                    switch (ch1) {
                        case 1: push(); break;
                        case 2: {
                            int poppedData = pop();
                            if (poppedData != -1) {
                                printf("Popped element is: %d\n", poppedData);
                            }
                            break;
                        }
                        case 3: display(); break;
                        case 4: break;
                        default: printf("Invalid choice!\n");
                    }
                    if (ch1 == 4) break;
                }
            } break;

            case 2: { clearList();
                while (1) {
                    printf("Linked list is being implemented as a queue!\n1.INSERT \n2.DELETE\n3.DISPLAY\n4.EXIT\n");
                    int ch1;
                    scanf("%d", &ch1);
                    switch (ch1) {
                        case 1: insert(); break;
                        case 2: {
                            int deletedData = delet();
                            if (deletedData != -1) {
                                printf("Deleted element is: %d\n", deletedData);
                            }
                            break;
                        }
                        case 3: display(); break;
                        case 4: break;
                        default: printf("Invalid choice!\n");
                    }
                    if (ch1 == 4) break;
                }
            } break;

            case 3: return 0; // Exit the program

            default: printf("Invalid choice!!\n");
        }
    }
}

void push() {
    new1 = (node*)malloc(sizeof(node));
    printf("Enter element:\n");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = NULL;
    } else {
        new1->link = start;
        start = new1;
    }
}

int pop() {
    if (start == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }

    temp = start;
    start = start->link;
    int data = temp->data;
    free(temp);
    return data;
}

void insert() {
    new1 = (node*)malloc(sizeof(node));
    printf("Enter element:\n");
    scanf("%d", &new1->data);

    if (start == NULL) {
        start = new1;
        new1->link = NULL;
    } else {
        temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new1;
        new1->link = NULL;
    }
}

int delet() {
    if (start == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    temp = start;
    start = start->link;
    int data = temp->data;
    free(temp);
    return data;
}

void display() {
    if (start == NULL) {
        printf("\nLinked list is empty.\n");
        return;
    }
    temp = start;
    printf("Elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void clearList()
{
    temp = start;
    while (temp != NULL) {
        start = temp->link;
        free(temp);
        temp = start;
    }
    printf("All nodes have been deleted. The list is now empty.\n");
}
