class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, size, count;

public:
    // Initialize your data structure
    MyCircularQueue(int k) {
        q.resize(k);
        size = k;
        front = 0;
        rear = -1;
        count = 0;
    }

    // Insert an element into the circular queue
    bool enQueue(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % size;
        q[rear] = value;
        count++;
        return true;
    }

    // Delete an element from the circular queue
    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % size;
        count--;
        return true;
    }

    // Get the front item
    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    // Get the last item
    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }

    // Check whether the circular queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check whether the circular queue is full
    bool isFull() {
        return count == size;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */