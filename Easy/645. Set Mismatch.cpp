// https://leetcode.com/problems/set-mismatch/

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {

        vector<int> answer;
        int duplicate, missed;
        map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i)
            freq[nums[i]]++;

        for (int i = 1; i <= nums.size(); ++i)
        {
            if (freq.find(i) != freq.end())
            {
                if (freq[i] == 2)
                    duplicate = i;
            }

            else
                missed = i;
        }

        answer.push_back(duplicate);
        answer.push_back(missed);

        return answer;
    }
};