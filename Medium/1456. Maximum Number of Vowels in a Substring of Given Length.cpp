// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int result = 0;
        int counter = 0;
        int i = 0;

        for (int j = 0; j < s.length(); ++j)
        {
            if (isVowel(s[j]))
                counter++;

            int windowSize = j - i + 1;

            if (windowSize == k)
            {
                result = max(result, counter);

                if (isVowel(s[i]))
                    counter--;

                ++i;
            }
        }

        return result;
    }

    bool isVowel(char letter)
    {
        return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
    }
};