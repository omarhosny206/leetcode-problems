// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        map<int, stack<int>, greater<int>> values;

        for (int &num : nums)
            freq[num]++;

        for (auto &pair : freq)
            values[pair.second].push(pair.first);

        for (auto &pair : values)
        {
            stack<int> vals = values[pair.first];
            while (!vals.empty() && k-- > 0)
            {
                result.push_back(vals.top());
                vals.pop();
            }

            if (k <= 0)
                break;
        }

        return result;
    }
};