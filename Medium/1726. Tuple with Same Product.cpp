// https://leetcode.com/problems/tuple-with-same-product/

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        int counter = 0;
        unordered_map<int, int> productFreq;

        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                productFreq[nums[i] * nums[j]]++;

        for (auto pair : productFreq)
            if (pair.second > 1)
                counter += ((pair.second - 1) * pair.second / 2) * 8;

        return counter;
    }
};