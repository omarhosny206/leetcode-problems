// https://leetcode.com/problems/crawler-log-folder/

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> directories;
        directories.push("Main");

        for (string &directory : logs)
        {
            if (directory == "../" && directories.top() != "Main")
                directories.pop();

            else if (directory != "./" && directory != "../")
                directories.push(directory);
        }

        return directories.size() - 1;
    }
};