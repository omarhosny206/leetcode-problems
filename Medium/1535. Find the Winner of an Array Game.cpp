// https://leetcode.com/problems/find-the-winner-of-an-array-game/

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int counter = 0;
        int max_element_index = 0;
        int i = 1;

        while (i < arr.size())
        {
            if (arr[max_element_index] > arr[i])
                counter++;

            else
            {
                max_element_index = i;
                counter = 1;
            }

            if (counter == k)
                return arr[max_element_index];

            i++;
        }

        return arr[max_element_index];
    }
};