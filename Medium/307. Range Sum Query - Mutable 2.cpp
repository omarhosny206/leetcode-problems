// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray
{
    vector<int> numbers;

public:
    NumArray(vector<int> &nums)
    {
        numbers = nums;
    }

    void update(int i, int val)
    {
        numbers[i] = val;
    }

    int sumRange(int i, int j)
    {
        int sum = 0;

        while (i <= j)
            sum += numbers[i++];

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */