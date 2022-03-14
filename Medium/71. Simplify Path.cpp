// https://leetcode.com/problems/simplify-path/

class Solution
{
public:
    string simplifyPath(string path)
    {
        string result = "";

        stack<string> directories = getDirectories(path);

        if (directories.empty())
            return "/";

        while (!directories.empty())
        {
            result = "/" + directories.top() + result;
            directories.pop();
        }

        return result;
    }

    stack<string> getDirectories(string &path)
    {
        stack<string> directories;
        string currentDirectory = "";

        path = path + "/";

        for (char &c : path)
        {
            if (c == '/')
            {
                if (!directories.empty() && currentDirectory == "..")
                    directories.pop();

                else if (currentDirectory != "" && currentDirectory != "." && currentDirectory != "..")
                    directories.push(currentDirectory);

                currentDirectory = "";
            }

            else
                currentDirectory += c;
        }

        return directories;
    }
};