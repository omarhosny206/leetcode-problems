// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack
{
    vector<int> nums;
    int maxSize;

public:
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
    }

    void push(int x)
    {
        if (nums.size() < maxSize)
            nums.push_back(x);
    }

    int pop()
    {
        if (nums.size() >= 1)
        {
            int top = nums.back();
            nums.pop_back();
            return top;
        }

        return -1;
    }

    void increment(int k, int val)
    {
        k = min(k, (int)nums.size());

        for (int i = 0; i < k; ++i)
            nums[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */