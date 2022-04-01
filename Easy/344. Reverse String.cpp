
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s);
    }

    void reverse(vector<char> &letters)
    {
        int i = 0;
        int j = letters.size() - 1;

        while (i < j)
        {
            char temp = letters[i];
            letters[i++] = letters[j];
            letters[j--] = temp;
        }
    }
};