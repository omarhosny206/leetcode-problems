// https://leetcode.com/problems/destination-city/

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> freq;

        for (int i = 0; i < paths.size(); ++i)
        {
            freq[paths[i][0]]++;
            freq[paths[i][1]]--;
        }

        for (auto pair : freq)
            if (pair.second == -1)
                return pair.first;

        return "";
    }
};