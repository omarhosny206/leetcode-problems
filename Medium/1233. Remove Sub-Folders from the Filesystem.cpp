// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string> result;

        sort(folder.begin(), folder.end());

        string current = folder[0];
        int index = current.size();

        for (int i = 1; i < folder.size(); ++i)
        {
            if (!(folder[i].find(current) == 0 && folder[i][index] == '/'))
            {
                result.push_back(current);
                current = folder[i];
                index = current.size();
            }
        }

        result.push_back(current);

        return result;
    }
};