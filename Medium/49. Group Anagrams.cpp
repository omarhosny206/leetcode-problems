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
            sort(word.begin(), word.end());

            anagrams[word].push_back(anagram);
        }

        for (auto &pair : anagrams)
            result.push_back(pair.second);

        return result;
    }
};