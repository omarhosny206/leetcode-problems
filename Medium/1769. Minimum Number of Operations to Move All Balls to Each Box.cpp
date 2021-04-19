// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> result(boxes.length());
        int lastCost = 0;
        int left = boxes[0] - '0';
        int right = boxes[boxes.length() - 1] - '0';

        for (int i = 1; i < boxes.length(); ++i)
        {
            result[i] += lastCost + left;
            lastCost = result[i];
            left += boxes[i] - '0';
        }

        lastCost = 0;

        for (int i = boxes.length() - 2; i >= 0; --i)
        {
            result[i] += lastCost + right;
            lastCost += right;
            right += boxes[i] - '0';
        }

        return result;
    }
};