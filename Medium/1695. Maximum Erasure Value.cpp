// https://leetcode.com/problems/maximum-erasure-value/

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        queue<int> unique;
        unordered_map<int, bool> seen;
        int sum = 0;
        int max_score = INT_MIN;

        for (int num : nums)
        {
            if (seen[num] == true)
            {
                while (num != unique.front())
                {
                    sum -= unique.front();
                    seen[unique.front()] = false;
                    unique.pop();
                }

                sum -= unique.front();
                unique.pop();
            }

            sum += num;
            max_score = max(max_score, sum);
            unique.push(num);
            seen[num] = true;
        }

        max_score = max(max_score, sum);
        return max_score;
    }
};