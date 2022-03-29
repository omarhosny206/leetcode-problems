
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> values;

        for (int &num : nums)
        {
            if (values.find(num) != values.end())
                return num;

            values.insert(num);
        }

        return -1;
    }
};