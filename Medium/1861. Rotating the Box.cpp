
// https://leetcode.com/problems/rotating-the-box/

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        vector<vector<char>> result(box[0].size(), vector<char>(box.size()));

        moveStones(box);
        flipBox(box, result);

        return result;
    }

    void moveStones(vector<vector<char>> &box)
    {
        for (int i = 0; i < box.size(); ++i)
        {
            for (int j = box[0].size() - 2; j >= 0; --j)
            {
                if (box[i][j] == '#')
                {
                    int column = j;

                    while (column + 1 < box[i].size() && box[i][column + 1] == '.')
                        column++;

                    swap(box[i][j], box[i][column]);
                }
            }
        }
    }

    void flipBox(vector<vector<char>> &box, vector<vector<char>> &result)
    {
        int column = result[0].size() - 1;

        for (int i = 0; i < box.size(); ++i)
        {
            int row = 0;

            for (int j = 0; j < box[0].size(); ++j)
            {
                result[row][column] = box[i][j];
                row++;
            }

            column--;
        }
    }
};