// https://leetcode.com/problems/check-array-formation-through-concatenation/

class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        unordered_map<int, int> position;

        for (int i = 0; i < arr.size(); ++i)
            position[arr[i]] = i;

        for (vector<int> &piece : pieces)
        {
            int i = position[piece[0]];

            for (int &num : piece)
            {
                if (position.find(num) == position.end() || arr[i] != num)
                    return false;

                i++;
            }
        }

        return true;
    }
};