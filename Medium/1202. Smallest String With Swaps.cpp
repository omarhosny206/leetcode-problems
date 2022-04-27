
class Solution
{
public:
    vector<int> root;

    int find(int x)
    {
        if (root[x] == x)
            return x;

        return root[x] = find(root[x]);
    }

    void unionset(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot != yRoot)
            root[yRoot] = xRoot;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        root.resize(n);

        for (int i = 0; i < n; i++)
            root[i] = i;

        for (auto p : pairs)
            unionset(p[0], p[1]);

        unordered_map<int, pair<int, string>> z;

        for (int i = 0; i < n; i++)
        {
            int r = find(i);
            string ss(1, s[i]);
            if (z.find(r) == z.end())
            {
                z[r] = {-1, ss};
            }
            else
                z[r].second += ss;
        }

        for (auto &p : z)
            sort(p.second.second.begin(), p.second.second.end());
        string res = "";

        for (int i = 0; i < n; i++)
        {
            int r = find(i);
            int index = ++z[r].first;
            res += z[r].second[index];
        }
        return res;
    }
};