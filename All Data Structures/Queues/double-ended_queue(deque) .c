#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct Deque {
    int* array;
    int front;
    int rear;
    int capacity;
} Deque;

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    if (!deque) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    deque->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (!deque->array) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    deque->front = -1;
    deque->rear = 0;
    deque->capacity = INITIAL_CAPACITY;

    return deque;
}

int isEmpty(Deque* deque) {
    return (deque->front == -1);
}

int isFull(Deque* deque) {
    return ((deque->front == 0 && deque->rear == deque->capacity - 1) ||
            deque->front == deque->rear + 1);
}

void resize(Deque* deque) {
    int newCapacity = deque->capacity * 2;
    int* newArray = (int*)malloc(newCapacity * sizeof(int));
    if (!newArray) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int j = deque->front;

    while (1) {
        newArray[i++] = deque->array[j];
        if (j == deque->rear)
            break;
        j = (j + 1) % deque->capacity;
    }

    free(deque->array);
    deque->array = newArray;
    deque->front = 0;
    deque->rear = deque->capacity - 1;
    deque->capacity = newCapacity;
}

void pushFront(Deque* deque, int item) {
    if (isFull(deque)) {
        resize(deque);
    }

    if (deque->front == -1)
        deque->front = deque->rear = 0;
    else if (deque->front == 0)
        deque->front = deque->capacity - 1;
    else
        deque->front--;

    deque->array[deque->front] = item;
}

void pushRear(Deque* deque, int item) {
    if (isFull(deque)) {
        resize(deque);
    }

    if (deque->front == -1)
        deque->front = deque->rear = 0;
    else if (deque->rear == deque->capacity - 1)
        deque->rear = 0;
    else
        deque->rear++;

    deque->array[deque->rear] = item;
}

int popFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        exit(EXIT_FAILURE);
    }

    int item = deque->array[deque->front];
    if (deque->front == deque->rear)
        deque->front = deque->rear = -1;
    else
        deque->front = (deque->front + 1) % deque->capacity;

    return item;
}

int popRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        exit(EXIT_FAILURE);
    }

    int item = deque->array[deque->rear];
    if (deque->front == deque->rear)
        deque->front = deque->rear = -1;
    else if (deque->rear == 0)
        deque->rear = deque->capacity - 1;
    else
        deque->rear--;

    return item;
}

void printDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    int i = deque->front;
    printf("Deque: ");
    while (1) {
        printf("%d ", deque->array[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % deque->capacity;
    }
    printf("\n");
}

int main() {
    Deque* deque = createDeque();

    pushFront(deque, 1);
    pushFront(deque, 2);
    pushRear(deque, 3);
    pushRear(deque, 4);

    printDeque(deque);

    printf("Popped from front: %d\n", popFront(deque));
    printf("Popped from rear: %d\n", popRear(deque));

    printDeque(deque);

    free(deque->array);
    free(deque);

    return 0;
}
