// https://leetcode.com/problems/merge-strings-alternately/

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result = "";
        int length1 = word1.size();
        int length2 = word2.size();
        int size = max(length1, length2);

        for (int i = 0; i < size; ++i)
        {
            if (length1)
            {
                result += word1[i];
                length1--;
            }

            if (length2)
            {
                result += word2[i];
                length2--;
            }
        }

        return result;
    }
};