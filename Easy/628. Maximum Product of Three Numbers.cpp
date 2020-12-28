// https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        make_heap(nums.begin(), nums.end());

        for (int i = 0; i < 3; i++)
            pop_heap(nums.begin(), nums.begin() + nums.size() - i);

        int max3[3];
        copy(nums.begin() + nums.size() - 3, nums.end(), max3);
        make_heap(nums.begin(), nums.end(), std::greater<int>());

        for (int i = 0; i < 3; i++)
            pop_heap(nums.begin(), nums.begin() + nums.size() - i, std::greater<int>());

        int min3[3];
        copy(nums.begin() + nums.size() - 3, nums.end(), min3);
        int answer = 0;
        answer = min3[2] * min3[1] * max3[2];
        answer = max(answer, max3[0] * max3[1] * max3[2]);
        answer = max(answer, min3[0] * min3[1] * min3[2]);

        return answer;
    }
};