// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        quickSort(arr, 0, arr.size() - 1);
        int DIFFERENCE = arr[1] - arr[0];

        for (int i = 1; i < arr.size() - 1; ++i)
            if (DIFFERENCE != arr[i + 1] - arr[i])
                return false;

        return true;
    }

    void quickSort(vector<int> &nodes, int left, int right)
    {
        if (left < right)
        {
            int pivotIndex = partition(nodes, left, right);
            quickSort(nodes, left, pivotIndex - 1);
            quickSort(nodes, pivotIndex, right);
        }
    }

    int partition(vector<int> &nodes, int left, int right)
    {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = nodes[pivotIndex];
        int i = left, j = right;
        int temp;

        while (i <= j)
        {
            while (nodes[i] < pivotValue)
                i++;

            while (nodes[j] > pivotValue)
                j--;

            if (i <= j)
            {
                temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
                i++;
                j--;
            }
        }

        return i;
    }
};