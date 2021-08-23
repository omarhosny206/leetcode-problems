// https://leetcode.com/problems/goat-latin/

class Solution
{
public:
    string toGoatLatin(string sentence)
    {
        string result = buildSentence(sentence);
        return result;
    }

    string buildSentence(string &sentence)
    {
        string result = "";
        string word = "";
        int counter = 1;

        for (int i = 0; i < sentence.length(); ++i)
        {
            if (sentence[i] == ' ')
            {
                word = Proccess(word, counter);
                result += word + " ";
                word = "";
                counter++;
            }

            else
                word += sentence[i];
        }

        word = Proccess(word, counter);
        result += word + " ";
        result.pop_back();

        return result;
    }

    string Proccess(string &word, int counter)
    {
        if (isVowel(tolower(word[0])))
            word += "ma";

        else
            word = word.substr(1, word.length() - 1) + word[0] + "ma";

        int k = 0;
        while (k++ < counter)
            word += 'a';

        return word;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};