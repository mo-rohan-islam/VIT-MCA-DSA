#include<stdio.h>
#include<stdlib.h>

#define ST_SIZE 5
#define ST_FULL_MSG "Stack is full!"
#define ST_EMPTY_MSG "Stack is empty!"
#define LINE "-----------------------"

struct Stack {
    int array[ST_SIZE];
    int top;
} s;

int is_empty() {
    if (s.top == -1)
        return 1;
    else
        return 0;
}

int is_full() {
    if (s.top == ST_SIZE-1)
        return 1;
    else
        return 0;
}

int push(int item) {
    if (is_full()) {
        printf("\n%s\n", ST_FULL_MSG);
        return -1;
    }
    s.array[++s.top] = item;
    return 0;
}

int pop() {
    if (is_empty()) {
        printf("\n%s\n", ST_EMPTY_MSG);
        return -1;
    }
    int item = s.array[s.top--];
    return item;
}

void display() {
    if (is_empty()) {
        printf("\n%s\n", ST_EMPTY_MSG);
    } else {
        printf("\n");
        for (int i = 0; i <= s.top; i++)
            printf("Position: %d | Item: %d\n", i+1, s.array[i]);
        printf("\n");
    }
}

void stack_stats() {
    printf("\nStack Capacity: %d", ST_SIZE);
    printf("\nItems in Stack: %d", s.top+1);
}

int main() {
    s.top = -1;
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
                int item; scanf("%d", &item);
                push(item);
                break;
            case 2:
                printf("\nItem popped: %d\n", pop());
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