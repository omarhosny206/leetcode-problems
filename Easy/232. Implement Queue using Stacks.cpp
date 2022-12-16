// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue
{
    stack<int> first;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stack<int> second;

        while (!first.empty())
        {
            second.push(first.top());
            first.pop();
        }

        first.push(x);

        while (!second.empty())
        {
            first.push(second.top());
            second.pop();
        }
    }

    int pop()
    {
        int value = first.top();
        first.pop();

        return value;
    }

    int peek()
    {
        return first.top();
    }

    bool empty()
    {
        return first.empty();
    }
};

/**
 * @brief 
 * 
 */
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */