// https://leetcode.com/problems/unique-morse-code-words/

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> MORSE = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                                "...-", ".--", "-..-", "-.--", "--.."};

        unordered_set<string> seen;
        for (string word : words)
        {
            string code = "";
            for (char c : word)
                code += MORSE[c - 'a'];

            seen.insert(code);
        }

        return seen.size();
    }
};