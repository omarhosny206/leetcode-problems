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
        return binarySearch(n, 0, n);
    }

    int binarySearch(int &n, int left, int right)
    {
        if (left > right)
            return -1;

        int middle = left + (right - left) / 2;

        if (guess(middle) == 0)
            return middle;

        if (guess(middle) == 1)
            return binarySearch(n, middle + 1, right);

        return binarySearch(n, left, middle - 1);
    }
};