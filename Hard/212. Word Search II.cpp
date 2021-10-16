// https://leetcode.com/problems/word-search-ii/

class Solution
{
    vector<string> result;

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (string word : words)
        {
            int exist = false;

            for (int i = 0; i < board.size(); ++i)
            {
                if (exist)
                    break;

                for (int j = 0; j < board[i].size(); ++j)
                {
                    if (DFS(board, word, 0, i, j))
                    {
                        result.push_back(word);
                        exist = true;
                        break;
                    }
                }
            }
        }

        return result;
    }

    bool DFS(vector<vector<char>> &board, string word, int position, int i, int j)
    {
        if (position == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || word[position] != board[i][j])
            return false;

        char temp = board[i][j];
        board[i][j] = '.';

        bool check = DFS(board, word, position + 1, i + 1, j) || DFS(board, word, position + 1, i - 1, j) ||
                     DFS(board, word, position + 1, i, j + 1) || DFS(board, word, position + 1, i, j - 1);

        board[i][j] = temp;

        return check;
    }
};