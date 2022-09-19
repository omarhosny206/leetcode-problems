// https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> values;

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        for (string &path : paths)
        {
            buildContentFilePaths(path);
        }

        for (auto &pair : values)
        {
            if (pair.second.size() > 1)
                result.push_back(pair.second);
        }

        return result;
    }

    void buildContentFilePaths(string &path)
    {
        string directory = "";
        string file = "";
        string content = "";

        int i = 0;

        while (path[i] != ' ')
            directory += path[i++];

        i++;

        while (i < path.size())
        {
            while (path[i] != '(')
                file += path[i++];

            i++;

            while (path[i] != ')')
                content += path[i++];

            i += 2;

            string value = directory + "/" + file;
            values[content].push_back(value);
            file = "";
            content = "";
        }
    }
};