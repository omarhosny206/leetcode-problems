// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> elements;
    int size;

public:
    KthLargest(int k, vector<int> &nums)
    {
        size = k;

        for (int &num : nums)
            elements.push(num);
    }

    int add(int val)
    {
        elements.push(val);

        while (elements.size() > size)
            elements.pop();

        return elements.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */