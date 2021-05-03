// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int result = 0;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int counter = 0;
        int i = 0;

        for (int j = 0; j < s.length(); ++j)
        {
            if (vowels.find(s[j]) != vowels.end())
                counter++;

            int windowSize = j - i + 1;

            if (windowSize == k)
            {
                result = max(result, counter);

                if (vowels.find(s[i]) != vowels.end())
                    counter--;

                ++i;
            }
        }

        return result;
    }
};