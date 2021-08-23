// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> result;
        int depth = log10(label) / log10(2);

        while (depth >= 0)
        {
            result.insert(result.begin(), label);
            label = (int)pow(2, depth - 1) + (int)pow(2, depth) - 1 - label / 2;
            depth--;
        }

        return result;
    }
};