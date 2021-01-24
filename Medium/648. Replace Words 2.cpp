// https://leetcode.com/problems/replace-words/

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string result = "";
        unordered_set<string> seen;
        for (string root : dictionary)
            seen.insert(root);

        istringstream words(sentence);
        string word = "";

        while (words >> word)
        {
            string prefix = "";

            for (char c : word)
            {
                prefix += c;
                if (seen.find(prefix) != seen.end())
                    break;
            }

            if (result.length() > 0)
                result += " ";

            result += prefix;
        }

        return result;
    }
};