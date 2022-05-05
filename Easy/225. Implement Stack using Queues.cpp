// https://leetcode.com/problems/implement-stack-using-queues/solution/

class MyStack
{
    queue<int> values;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        int size = values.size();
        values.push(x);

        while (size--)
        {
            values.push(values.front());
            values.pop();
        }
    }

    int pop()
    {
        int result = values.front();
        values.pop();

        return result;
    }

    int top()
    {
        return values.front();
    }

    bool empty()
    {
        return values.empty();
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