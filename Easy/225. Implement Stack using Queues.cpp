// https://leetcode.com/problems/implement-stack-using-queues/solution/

class MyStack
{
    queue<int> Queue;

public:
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        int sz = Queue.size();
        Queue.push(x);
        while (sz--)
        {
            Queue.push(Queue.front());
            Queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int result = Queue.front();
        Queue.pop();
        return result;
    }

    /** Get the top element. */
    int top()
    {
        return Queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return Queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */