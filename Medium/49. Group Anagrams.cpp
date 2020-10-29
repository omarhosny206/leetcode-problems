// https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mapping;
        for (auto s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mapping[key].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mapping)
            anagrams.push_back(p.second);

        return anagrams;
    }
};