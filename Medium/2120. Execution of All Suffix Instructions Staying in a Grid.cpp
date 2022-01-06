// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/

class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        vector<int> result(s.length());

        for (int i = 0; i < s.length(); ++i)
        {
            string instructions = s.substr(i, s.length() - i);

            int row = startPos[0];
            int column = startPos[1];
            int j = 0;

            while (j < instructions.length() && canApplyInstruction(instructions[j], n, row, column))
                j++;

            result[i] = j;
        }

        return result;
    }

    bool canApplyInstruction(char instruction, int size, int &row, int &column)
    {
        applyInstruction(instruction, row, column);
        return isInside(size, row, column);
    }

    void applyInstruction(char instruction, int &row, int &column)
    {
        if (instruction == 'L')
            column--;

        else if (instruction == 'R')
            column++;

        else if (instruction == 'U')
            row--;

        else
            row++;
    }

    bool isInside(int size, int row, int column)
    {
        return row >= 0 && row < size && column >= 0 && column < size;
    }
};