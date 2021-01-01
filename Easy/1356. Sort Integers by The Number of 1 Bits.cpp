// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int first = countOnes(a), second = countOnes(b);
            return (first < second || (first == second && a < b));
        });

        return arr;
    }

    int countOnes(int number)
    {
        int answer = 0;

        while (number > 0)
        {
            if (number % 2 != 0)
                answer++;

            number /= 2;
        }

        return answer;
    }
};