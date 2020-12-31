// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int answer = 0;

        for (int i = 0; i < mat.size(); ++i)
        {
            int row_ones = 0;
            int column_ones = 0;
            int position = 0;
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (mat[i][j] == 1)
                {
                    row_ones++;
                    position = j;
                }
            }

            if (row_ones == 1)
                for (int k = 0; k < mat.size(); ++k)
                    if (mat[k][position] == 1)
                        column_ones++;

            answer = (row_ones == 1 && column_ones == 1) ? answer + 1 : answer;
        }

        return answer;
    }
};