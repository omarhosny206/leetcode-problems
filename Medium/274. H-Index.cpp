// https://leetcode.com/problems/h-index/

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (citations[middle] < n - middle)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return n - left;
    }
};