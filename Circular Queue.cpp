#include <iostream>
using namespace std;

#define SIZE 5  // maximum size of the circular queue

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Add element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full (Overflow)" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        items[rear] = value;
        cout << "Inserted " << value << endl;
    }

    // Remove element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty (Underflow)" << endl;
            return;
        }

        cout << "Deleted " << items[front] << endl;

        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // View the front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Front element: " << items[front] << endl;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
