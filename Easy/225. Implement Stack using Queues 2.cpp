// https://leetcode.com/problems/implement-stack-using-queues/solution/

class MyStack
{
    queue<int> first;
    queue<int> second;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        second.push(x);

        while (!first.empty())
        {
            second.push(first.front());
            first.pop();
        }

        queue<int> temp = second;
        second = first;
        first = temp;
    }

    int pop()
    {
        int result = first.front();
        first.pop();

        return result;
    }

    int top()
    {
        return first.front();
    }

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