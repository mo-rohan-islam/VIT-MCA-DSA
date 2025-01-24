#include <stdio.h>
#include <stdlib.h>

#define Q_EMPTY_MSG "Queue is empty!"
#define DEFAULT_MSG "Invalid choice!"
#define MEM_ALLOC_FAILED_MSG "Memory allocation failed!"
#define LINE "-----------------------"

int Q_SIZE = 0;

struct Node {
    int data;
    struct Node *next;
} *node, *front, *rear;

int is_empty() {
    return !Q_SIZE ? 1 : 0;
}

int enqueue(int item) {
    node = (struct Node *) malloc (sizeof(struct Node));
    if (node == NULL) {
        printf("\n%s\n", MEM_ALLOC_FAILED_MSG);
        return 0;
    }
    node->data = item;
    node->next = NULL;

    if (rear == NULL)
        rear = front = node;
    else {
        rear->next = node;
        rear = node;
    }

    Q_SIZE++;
    return 1;
}

int dequeue() {
    if (is_empty()) {
        printf("\n%s\n", Q_EMPTY_MSG);
        return 0;
    }
    node = front;
    int item = node->data;

    if (front == rear)
        front = rear = NULL;
    else
        front = node->next;

    Q_SIZE--;
    free(node);
    return item;
}

int display() {
    if (is_empty()) {
       printf("\n%s\n", Q_EMPTY_MSG);
       return 0;
    }
    int position = 0;
    node = front;

    while (node != NULL) {
        printf("Position: %d | Item: %d\n", ++position, node->data);
        node = node->next;
    }
    return 1;
}

void statistics() {
    printf("\nItems in queue: %d", Q_SIZE);
}

int main() {
    front = rear = NULL;
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