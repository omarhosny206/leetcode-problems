// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution
{
    int answer = 0;

public:
    int countVowelStrings(int n)
    {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        DFS(n, ' ', vowels);
        return answer;
    }

    void DFS(int n, char letter, vector<char> &vowels)
    {
        if (n == 0)
        {
            answer++;
            return;
        }

        for (char c : vowels)
            if (letter <= c)
                DFS(n - 1, c, vowels);
    }
};