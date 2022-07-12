// https://leetcode.com/problems/matchsticks-to-square/

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = 0;

        for (int &stick : matchsticks)
            sum += stick;

        if (sum == 0 || sum % 4)
            return false;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        vector<int> bucket(4, 0);
        return canMakeSquare(0, sum / 4, matchsticks, bucket);
    }

    bool canMakeSquare(int index, int bucketsize, vector<int> &matchsticks, vector<int> &bucket)
    {
        if (index == matchsticks.size())
            return bucket[0] == bucket[1] and bucket[1] == bucket[2] and bucket[2] == bucket[3];

        for (int i = 0; i < 4; i++)
        {
            if (bucket[i] + matchsticks.at(index) > bucketsize)
                continue;

            int j = i;

            while (--j >= 0)
                if (bucket[i] == bucket[j])
                    break;

            if (j != -1)
                continue;

            bucket.at(i) += matchsticks.at(index);

            if (canMakeSquare(index + 1, bucketsize, matchsticks, bucket))
                return true;

            bucket.at(i) -= matchsticks.at(index);
        }

        return false;
    }
};