#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node* NODE;


NODE getnode() {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (new_node==NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}
NODE insert_end(int item, NODE first) {
    NODE new_end = getnode();
    new_end->value = item;
    new_end->next = NULL;

    if (first == NULL) {
        return new_end;
    }

    NODE current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_end;
    return first;
}

NODE reverse(NODE first){
    NODE current,temp;
    current=NULL;
    while (first!=NULL){
        temp=first;
        first=first->next;
        temp->next=current;
        current=temp;
    }
    return current;
}

NODE concatenate(NODE first_1, NODE first_2){
     NODE last1;
     if (first_1==NULL && first_2==NULL){
        return NULL;
     }
     else if(first_1==NULL){
        return first_2;
     }
     else if (first_2==NULL){
        return first_1;
     }
     else{
        last1=first_1;
        while(last1->next!=NULL){
            last1=last1->next;
        }
        last1->next=first_2;
     }
     return first_1;
}

NODE sort(NODE start) {
    NODE temp1, temp2;
    temp1 = start;


    while (temp1 != NULL) {
        temp2 = temp1->link;

        while (temp2 != NULL) {
            if (temp1->data > temp2->data) {

                int x = temp1->data;
                temp1->data = temp2->data;
                temp2->data = x;
            }
            temp2 = temp2->link;
        }

        temp1 = temp1->link;
    }

    return start;
}


void display(NODE first)
{ NODE temp;

    if(first==NULL)
    {

        printf("linked list is empty");
        return;
    }
     temp=first;
    while(temp!=NULL)
    {

        printf("%d\t",temp->value);
        temp=temp->next;
    }
}

int main() {
    NODE first_1= NULL;
    NODE first_2= NULL;
    int choice, item, pos;
    while (1){
        printf("\nMenu:\n");
        printf("1. Insert in linked list 1\n ");
        printf("2. Insert in linked list 2\n");
        printf("3. Sort in linked list 1\n");
        printf("4. Sort in linked list 2\n");
        printf("5. Reverse in linked list 1\n");
        printf("6. Reverse in linked list 2\n");
        printf("7. Concatenate the two lists\n");
        printf("8. Display LL 1\n");
        printf("9. Display LL 2\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //insert_end(int item, NODE first)
                printf("Enter value to insert: ");
                scanf("%d", &item);
                first_1 = insert_end(item, first_1);
                break;
            case 2:
                //insert_end(int item, NODE first)
                printf("Enter value to insert: ");
                scanf("%d", &item);
                first_2 = insert_end(item, first_2);
                break;
            case 3:
                //NODE sort(NODE first)
                printf("Sorting LL1");
                first_1=sort(first_1);
                break;
            case 4:
                //NODE sort(NODE first)
                printf("Sorting LL2");
                first_2=sort(first_2);
                break;
            case 5:
                //NODE reverse(NODE first)
                printf("LL1 being reversed");
                first_1 =reverse(first_1);
                break;
            case 6:
                //NODE reverse(NODE first)
                printf("LL2 being reversed");
                first_2=reverse (first_2);
                break;
            case 7:
                //NODE concatenate(NODE first_1, NODE first_2
                first_1=concatenate (first_1,first_2);
                break;
            case 8:
                //void display(NODE first)
                display(first_1);
                break;
            case 9:
                //void display(NODE first)
                display(first_2);
                break;
            default:
                printf("Invalid choice. \n");
        }
    }

    return 0;
}
