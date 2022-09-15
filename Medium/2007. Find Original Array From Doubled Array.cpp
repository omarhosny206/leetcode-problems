// https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        vector<int> result;
        unordered_map<int, int> freq;

        for (int &value : changed)
            freq[value]++;

        sort(changed.begin(), changed.end());

        for (int i = 0; i < changed.size(); ++i)
        {
            int currentValue = changed[i];
            int doubledValue = changed[i] * 2;

            if (freq[currentValue] == 0)
                continue;

            int size = freq[currentValue];

            if (currentValue == 0)
            {
                if (freq[currentValue] % 2 != 0)
                    return {};

                size = freq[currentValue] / 2;
            }

            else if (freq[currentValue] > freq[doubledValue])
                return {};

            for (int j = 0; j < size; ++j)
                result.push_back(currentValue);

            freq[doubledValue] -= freq[currentValue];
            freq[currentValue] = 0;
        }

        return result;
    }
};