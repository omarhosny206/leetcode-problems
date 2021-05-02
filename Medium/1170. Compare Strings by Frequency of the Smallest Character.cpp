// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> result;
        vector<int> freq;

        for (string word : words)
            freq.push_back(getFrequency(word));

        sort(freq.begin(), freq.end());

        for (string query : queries)
        {
            int queryFreq = getFrequency(query);
            result.push_back(binarySearch(freq, queryFreq, 0, freq.size() - 1));
        }

        return result;
    }

    int binarySearch(vector<int> &freq, int queryFreq, int left, int right)
    {
        int result = 0;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (freq[middle] > queryFreq)
            {
                result = max(result, (int)freq.size() - middle);
                right = middle - 1;
            }

            else
                left = middle + 1;
        }

        return result;
    }

    int getFrequency(string word)
    {
        vector<int> freq(26);

        for (char c : word)
            freq[c - 'a']++;

        for (int i = 0; i < 26; ++i)
            if (freq[i] > 0)
                return freq[i];

        return -1;
    }
};