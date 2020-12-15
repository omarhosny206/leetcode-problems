// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        vector<int> answer;
        int current = K;

        int i = A.size();
        while (--i >= 0 || current > 0)
        {
            if (i >= 0)
                current += A[i];

            answer.push_back(current % 10);
            current /= 10;
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};