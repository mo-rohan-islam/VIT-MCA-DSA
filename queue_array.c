#include <stdio.h>
#include<stdlib.h>

#define Q_SIZE 5
#define Q_FULL_MSG "Queue is full!"
#define Q_EMPTY_MSG "Queue is empty!"
#define DEFAULT_MSG "Invalid choice!"
#define LINE "-----------------------"

struct Queue {
    int array[Q_SIZE];
    int front, rear;
} q;

int is_empty() {
    return (q.rear == -1) ? 1 : 0;
}

int is_full() {
    return (q.rear == Q_SIZE-1) ? 1 : 0;
}

int enqueue(int item) {
    if (is_full()) {
        printf ("\n%s\n", Q_FULL_MSG);
        return 0;
    }

    q.array[++q.rear] = item;
    q.front = (q.front == -1) ? 0 : q.front; 

    return 1;
}

int dequeue() {
    if (is_empty()) {
        printf("\n%s\n", Q_EMPTY_MSG);
        return 0;
    }

    int item = q.array[q.front];

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        for (int i=q.front; i < q.rear; i++)
            q.array[i] = q.array[i+1];
        q.rear--;
    }

    return item;
}

void display() {
    if (is_empty())
        printf("\n%s\n", Q_EMPTY_MSG);
    else {
        printf("\n");
        for (int i = q.front; i <= q.rear; i++)
            printf("Position: %d | Item: %d\n", i+1, q.array[i]);
        printf("\n");
    }
}

void statistics() {
    printf("\nQueue capacity: %d", Q_SIZE);
    printf("\nItems in queue: %d", q.rear+1);
}

int main() {
    q.front = q.rear = -1;
    int item; 
    do {
        printf("\n%s\n", LINE);
        printf("Enter 1 to add\n");
        printf("Enter 2 to remove\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 for queue stats\n");
        printf("Enter 5 to exit\n");
        printf("\nEnter your choice: ");
        int choice; scanf("%d",&choice);
        printf("%s\n", LINE);

        switch(choice) {
            case 1:
                printf("\nEnter item to add: ");
                scanf("%d", &item);
                if (enqueue(item))
                    printf("\nItem added: %d\n", item);
                break;
            case 2:
                if (item = dequeue())
                    printf("\nItem removed: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                statistics();
                break;
            case 5:
                exit(0);
            default:
                printf("\n%s\n", DEFAULT_MSG);
        }
    } while (1);

    return 0;
}