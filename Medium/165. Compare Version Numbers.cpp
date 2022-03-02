// https://leetcode.com/problems/compare-version-numbers/

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        return compare(version1, version2);
    }

    int compare(string &first, string &second)
    {
        int i = 0;
        int j = 0;

        while (i < first.length() || j < second.length())
        {
            int firstSum = 0;
            while (i < first.length() && first[i] != '.')
            {
                firstSum = firstSum * 10 + (first[i] - '0');
                i++;
            }

            int secondSum = 0;
            while (j < second.length() && second[j] != '.')
            {
                secondSum = secondSum * 10 + (second[j] - '0');
                j++;
            }

            if (firstSum > secondSum)
                return 1;

            else if (firstSum < secondSum)
                return -1;

            i++;
            j++;
        }

        return 0;
    }
};