class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        unordered_map<string, int> position;
        int i = 0;
        int j = 0;
        position[needle] = -1;

        while (j < haystack.length())
        {
            int windowSize = j - i + 1;

            if (windowSize == needle.length())
            {
                string word = haystack.substr(i, j - i + 1);

                if (position[word] == -1)
                    return i;

                i++;
            }

            j++;
        }

        return -1;
    }
};