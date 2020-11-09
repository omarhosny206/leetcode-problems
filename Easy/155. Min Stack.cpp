// https://leetcode.com/problems/min-stack/

class MinStack
{
public:
    stack<long> minStack;
    long minElement;
    MinStack()
    {
        minElement = INT_MAX;
    }

    void push(int x)
    {
        if (minStack.empty())
        {
            minStack.push(0);
            minElement = x;
        }
        else
        {
            minStack.push(x - minElement);
            if (minStack.top() < 0)
                minElement = x;
        }
    }

    void pop()
    {
        if (minStack.top() < 0)
            minElement = minElement - minStack.top();

        minStack.pop();
    }

    int top()
    {
        if (minStack.top() < 0)
            return minElement;
        return minElement + minStack.top();
    }

    int getMin()
    {
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */