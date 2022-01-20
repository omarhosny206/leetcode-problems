// https://leetcode.com/problems/queries-on-a-permutation-with-key/

class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> result(queries.size());
        vector<int> currentPermutation(m);

        initialPermutation(currentPermutation);

        for (int i = 0; i < queries.size(); ++i)
        {
            int target = queries[i];

            int j = findPosition(currentPermutation, target);

            result[i] = j;

            move(currentPermutation, j);
        }

        return result;
    }

    void move(vector<int> &currentPermutation, int position)
    {
        while (position >= 1)
        {
            int temp = currentPermutation[position];
            currentPermutation[position] = currentPermutation[position - 1];
            currentPermutation[position - 1] = temp;
            position--;
        }
    }

    int findPosition(vector<int> &currentPermutation, int target)
    {
        for (int i = 0; i < currentPermutation.size(); ++i)
            if (target == currentPermutation[i])
                return i;

        return -1;
    }

    void initialPermutation(vector<int> &currentPermutation)
    {
        for (int i = 0; i < currentPermutation.size(); ++i)
            currentPermutation[i] = i + 1;
    }
};