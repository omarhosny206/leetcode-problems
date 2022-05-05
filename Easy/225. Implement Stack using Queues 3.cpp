// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack
{
    queue<int> values;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        queue<int> temp;

        while (!values.empty())
        {
            temp.push(values.front());
            values.pop();
        }

        values.push(x);

        while (!temp.empty())
        {
            values.push(temp.front());
            temp.pop();
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