// https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;

        for (string &word : strs)
        {
            string anagram = word;
            string sorted = getSorted(word);

            anagrams[sorted].push_back(anagram);
        }

        for (auto &pair : anagrams)
            result.push_back(pair.second);

        return result;
    }

    string getSorted(string &word)
    {
        vector<int> freq(26);
        string sorted;

        for (char &c : word)
            freq[c - 'a']++;

        for (int i = 0; i < 26; ++i)
            if (freq[i] > 0)
                sorted += string(freq[i], (i + 'a'));

        return sorted;
    }
};