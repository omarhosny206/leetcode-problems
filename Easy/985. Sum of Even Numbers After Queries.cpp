// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> answer;
        int sum = 0;

        for (int num : A)
            if (num % 2 == 0)
                sum += num;

        for (int i = 0; i < A.size(); i++)
        {
            int value = queries[i][0];
            int index = queries[i][1];

            if (A[index] % 2 == 0)
                sum -= A[queries[i][1]];

            A[index] += value;

            if (A[index] % 2 == 0)
                sum += A[index];

            answer.push_back(sum);
        }

        return answer;
    }
};