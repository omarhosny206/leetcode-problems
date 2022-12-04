// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

class Solution
{
public:
    long long dividePlayers(vector<int> &skills)
    {
        long long result = 0;

        sort(skills.begin(), skills.end());

        if (check(skills) == false)
            return -1;

        result = getProductSum(skills);
        return result;
    }

    long long getProductSum(vector<int> skills)
    {
        long long result = 0;

        int i = 0;
        int j = skills.size() - 1;

        while (i < j)
        {
            result += skills[i] * skills[j];

            i++;
            j--;
        }

        return result;
    }

    bool check(vector<int> skills)
    {
        int value = skills[0] + skills[skills.size() - 1];

        int i = 0;
        int j = skills.size() - 1;

        while (i < j)
        {
            int current = skills[i] + skills[j];

            if (current != value)
                return false;

            i++;
            j--;
        }

        return true;
    }
};