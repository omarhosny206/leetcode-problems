// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue
{
    vector<int> queue;
    int front;
    int rear;
    int actualSize = 0;

public:
    MyCircularQueue(int k)
    {
        queue = vector<int>(k);
        front = -1;
        rear = -1;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
        {
            front = 0;
        }

        rear = (rear + 1) % queue.size();
        queue[rear] = value;
        actualSize++;

        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        front = (front + 1) % queue.size();
        actualSize--;

        if (actualSize == 0)
        {
            front = -1;
            rear = -1;
        }

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;

        return queue[front];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;

        return queue[rear];
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((rear + 1) % queue.size()) == front;
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