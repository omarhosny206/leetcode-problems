// https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack
{
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> nums;
    int maxFreq = 0;

public:
    FreqStack()
    {
    }

    void push(int val)
    {
        freq[val]++;

        if (freq[val] > maxFreq)
            maxFreq = freq[val];

        nums[freq[val]].push(val);
    }

    int pop()
    {
        int result = nums[maxFreq].top();
        nums[maxFreq].pop();

        freq[result]--;

        if (nums[maxFreq].size() == 0)
            maxFreq--;

        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */