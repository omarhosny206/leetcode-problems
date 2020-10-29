// https://leetcode.com/problems/keyboard-row/

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {

        set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> result;

        for (string s : words)
        {

            int r1 = 0, r2 = 0, r3 = 0;

            for (char c : s)
            {

                if (c < 'a')
                    c += 32;

                if (row1.count(c))
                    r1 = 1;
                if (row2.count(c))
                    r2 = 1;
                if (row3.count(c))
                    r3 = 1;

                if (r1 + r2 + r3 > 1)
                    break;
            }

            if (r1 + r2 + r3 == 1)
                result.push_back(s);
        }

        return result;
    }
};