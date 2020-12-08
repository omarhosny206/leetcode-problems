// https://leetcode.com/problems/implement-stack-using-queues/solution/

class MyStack
{
    queue<int> first;
    queue<int> second;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        second.push(x);
        while (!first.empty())
        {
            second.push(first.front());
            first.pop();
        }

        queue<int> temp;
        temp = second;
        second = first;
        first = temp;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int p = first.front();
        first.pop();
        return p;
    }

    /** Get the top element. */
    int top()
    {
        return first.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return first.empty();
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