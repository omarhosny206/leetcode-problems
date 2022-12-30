// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/

class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int result = INT_MAX;
        unordered_set<string> values;

        if (words[startIndex] == target)
            return 0;

        for (string &word : words)
            values.insert(word);

        if (values.find(target) == values.end())
            return -1;

        for (int i = 0; i < words.size(); ++i)
        {
            int index = (i + startIndex + 1) % words.size();

            if (words[index] == target)
            {
                result = min(result, i + 1);
                break;
            }
        }

        int j = 0;
        for (int i = startIndex; j < words.size(); --i)
        {
            int index = (i - 1 + words.size()) % words.size();

            if (words[index] == target)
            {
                result = min(result, j + 1);
                break;
            }

            ++j;
        }

        return result;
    }
};