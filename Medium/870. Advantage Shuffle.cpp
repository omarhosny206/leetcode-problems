// https://leetcode.com/problems/advantage-shuffle/

class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        multiset<int> vals;
        for (int n : A)
            vals.insert(n);

        for (int i = 0; i < B.size(); i++)
        {
            auto itr = vals.lower_bound(B[i] + 1);

            if (itr == vals.end())
                itr = vals.begin();

            A[i] = *itr;
            vals.erase(itr);
        }

        return A;
    }
};