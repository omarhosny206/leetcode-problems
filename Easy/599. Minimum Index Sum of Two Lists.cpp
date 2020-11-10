// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        vector<string> result;
        unordered_map<string, int> mapping;
        int min_sum = INT_MAX;

        for (int i = 0; i < list1.size(); ++i)
            mapping[list1[i]] = i;

        for (int i = 0; i < list2.size(); ++i)
        {
            if (mapping.find(list2[i]) != mapping.end())
            {

                int sum = mapping[list2[i]] + i;
                if (sum < min_sum)
                    result.clear();
                if (sum <= min_sum)
                {
                    result.push_back(list2[i]);
                    min_sum = sum;
                }
            }
        }

        return result;
    }
};