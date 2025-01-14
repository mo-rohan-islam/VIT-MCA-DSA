#include <stdio.h>
#include <stdlib.h>

#define ST_EMPTY_MSG "Stack is empty!"
#define LINE "-----------------------"

int is_empty();
int push(int);
int pop();
int display();
int size();
void stack_stats();

struct Node {
    int data;
    struct Node *next;
} *node, *top;

int is_empty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

int push(int data) {
    node = (struct Node *) malloc (sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed!");
        return -1;
    }
    node->data = data;
    node->next = top;
    top = node;
    return 1;
}

int pop() {
    if (is_empty()) {
        printf("\n%s\n", ST_EMPTY_MSG);
        return -1;
    }
    node = top;
    int data = top->data;
    top = top->next;
    free(node);
    return data;
}

int size() {
    int item_count = 0;
    node = top;
    while (node != NULL) {
        item_count++;
        node = node->next;
    }
    return item_count;
}

int display() {
    int stack_size = size();
    node = top;
    if (stack_size == 0) {
       printf("\n%s\n", ST_EMPTY_MSG);
       return -1;
    }

    while (node != NULL) {
        printf("Position: %d | Item: %d\n", stack_size--, node->data);
        node = node->next;
    }
    return 0;
}

void stack_stats() {
    printf("\nItems in Stack: %d", size());
}

int main() {
    top = NULL;
    int item;
    do {
        printf("\n%s\n", LINE);
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 for stack stats\n");
        printf("Enter 5 to exit\n");
        printf("\nEnter your choice: ");
        int choice; scanf("%d",&choice);
        printf("%s\n", LINE);

        switch(choice) {
            case 1:
                printf("\nEnter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1)
                    printf("\nItem popped: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                stack_stats();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    } while (1);

    return 0;
}