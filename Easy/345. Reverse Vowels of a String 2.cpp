
class Solution
{
public:
    string reverseVowels(string s)
    {
        string result = "";
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int i = 0;
        int j = s.length() - 1;

        while (i < j)
        {
            while (i < j && vowels.find(tolower(s[i])) == vowels.end())
                i++;

            while (i < j && vowels.find(tolower(s[j])) == vowels.end())
                j--;

            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }

    void swap(char &first, char &second)
    {
        char temp = first;
        first = second;
        second = temp;
    }
};