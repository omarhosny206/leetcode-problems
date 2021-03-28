// https://leetcode.com/problems/number-of-different-integers-in-a-string/

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        set<string> nums;
        string currentNumber = "";

        for (int i = 0; i <= word.length(); ++i)
        {

            if (word[i] >= '0' && word[i] <= '9')
                currentNumber += word[i];

            else if (currentNumber != "")
            {
                string number = removeLeadingZeroes(currentNumber);
                nums.insert(number);
                currentNumber = "";
            }
        }

        return nums.size();
    }

    string removeLeadingZeroes(string number)
    {
        int i = 0;

        while (number[i] == '0')
            i++;

        return number.substr(i);
    }
};