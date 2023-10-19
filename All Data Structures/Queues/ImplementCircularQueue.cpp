#include <iostream>

class CircularQueue {
private:
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        size = 0;
        front = 0;
        rear = -1;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Error code
        }

        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return -1; // Error code
        }
        return queue[front];
    }

    int getSize() {
        return size;
    }

    ~CircularQueue() {
        delete[] queue;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);

    std::cout << "Queue size: " << cq.getSize() << std::endl;
    std::cout << "Front item: " << cq.peek() << std::endl;

    cq.dequeue();
    cq.enqueue(6);

    std::cout << "Queue size after dequeue and enqueue: " << cq.getSize() << std::endl;
    std::cout << "Front item after dequeue and enqueue: " << cq.peek() << std::endl;

    return 0;
}
