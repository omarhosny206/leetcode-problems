// https://leetcode.com/problems/guess-number-higher-or-lower/

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        return binarySearch(n);
    }

    int binarySearch(int &n)
    {
        int left = 1;
        int right = n;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (guess(middle) == 0)
                return middle;

            if (guess(middle) == 1)
                left = middle + 1;

            else
                right = middle - 1;
        }

        return -1;
    }
};