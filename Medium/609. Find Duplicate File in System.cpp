// https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution
{
    unordered_map<string, vector<string>> files;

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        vector<vector<string>> result;

        for (auto path : paths)
            buildContentFiles(path);

        for (auto pair : files)
            if (pair.second.size() > 1)
                result.push_back(pair.second);

        return result;
    }

    void buildContentFiles(string path)
    {
        string directory = "";
        int i = 0;

        while (path[i] != ' ')
            directory += path[i++];

        directory += '/';
        ++i;

        while (i < path.length())
        {
            string file = "";
            string content = "";

            while (path[i] != '(')
                file += path[i++];

            ++i;

            while (path[i] != ')')
                content += path[i++];

            i += 2;

            files[content].push_back(directory + file);
        }
    }
};