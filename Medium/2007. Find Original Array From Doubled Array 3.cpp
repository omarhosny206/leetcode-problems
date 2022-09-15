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
            if (freq[changed[i]] == 0)
                continue;

            if (freq[changed[i]] > freq[changed[i] * 2] || (changed[i] == 0 && freq[changed[i]] % 2 != 0))
                return {};

            int size = freq[changed[i]];
            if (changed[i] == 0)
                size = freq[changed[i]] / 2;

            for (int j = 0; j < size; ++j)
                result.push_back(changed[i]);

            freq[changed[i] * 2] -= freq[changed[i]];
            freq[changed[i]] = 0;
        }

        return result;
    }
};