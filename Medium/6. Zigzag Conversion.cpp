
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string result = "";
        vector<string> words(numRows);
        
        int row = 0;
        bool moveToDown = true;

        for (char &c : s)
        {
            words[row] += c;

            if (row == 0)
                moveToDown = true;

            if (row == numRows - 1)
                moveToDown = false;

            row = (moveToDown) ? row + 1 : row - 1;
        }

        for (string &word : words)
            result += word;

        return result;
    }
};