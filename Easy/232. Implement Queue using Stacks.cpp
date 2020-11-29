// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue
{
    stack<int> frontStack;
    stack<int> backStack;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        if (frontStack.size() == 0)
            frontStack.push(x);

        else if (frontStack.size() == 1 && backStack.size() == 0)
            backStack.push(x);

        else if (frontStack.size() == 1 && backStack.size() > 0)
        {
            vector<int> temp;
            while (backStack.size() != 0)
            {
                temp.push_back(backStack.top());
                backStack.pop();
            }
            backStack.push(x);
            int i = temp.size() - 1;
            while (i >= 0)
                backStack.push(temp[i--]);
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int get = frontStack.top();
        frontStack.pop();
        if (!(backStack.empty()))
        {
            frontStack.push(backStack.top());
            backStack.pop();
        }
        return get;
    }

    /** Get the front element. */
    int peek()
    {
        return frontStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return frontStack.size() == 0 && backStack.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */