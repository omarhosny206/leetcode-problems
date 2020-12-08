// https://leetcode.com/problems/h-index-ii/

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        if (citations.empty())
            return 0;

        int n = citations.size();
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int middle = left + (right - left) / 2;

            if (citations[middle] >= n - middle)
                right = middle;

            else
                left = middle + 1;
        }

        if (citations[left] < n - left)
            return 0;

        return n - left;
    }
};