// https://leetcode.com/problems/implement-magic-dictionary/

class MagicDictionary
{
    unordered_map<int, vector<string>> words;

public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
    }

    void buildDict(vector<string> dictionary)
    {
        for (string &word : dictionary)
            words[word.size()].push_back(word);
    }

    bool search(string searchWord)
    {
        if (words.find(searchWord.size()) == words.end())
            return false;

        for (string &word : words[searchWord.size()])
        {
            int counter = 0;

            for (int i = 0; i < searchWord.size(); ++i)
                if (searchWord[i] != word[i])
                    counter++;

            if (counter == 1)
                return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */