// https://leetcode.com/problems/jump-game-iv/

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        if (arr.size() == 1)
            return 0;

        int result = 0;
        queue<int> q;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]].push_back(i);

        q.push(0);
        while (!q.empty())
        {
            result++;
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                int a = q.front();
                q.pop();

                if (a - 1 >= 0 && mp.find(arr[a - 1]) != mp.end())
                    q.push(a - 1);

                if (a + 1 < arr.size() && mp.find(arr[a + 1]) != mp.end())
                {
                    if (a + 1 == arr.size() - 1)
                        return result;
                    q.push(a + 1);
                }

                if (mp.find(arr[a]) != mp.end())
                {
                    for (auto k : mp[arr[a]])
                        if (k != a)
                        {
                            if (k == arr.size() - 1)
                                return result;
                            q.push(k);
                        }
                }

                mp.erase(arr[a]);
            }
        }

        return result;
    }
};