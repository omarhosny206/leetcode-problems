// https://leetcode.com/problems/defuse-the-bomb/

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        if (k == 0)
            return vector<int>(code.size(), 0);

        vector<int> result(code.size());
        if (k > 0)
        {
            for (int i = 0; i < code.size(); ++i)
            {
                result[i] = 0;
                int j = i + 1;

                int t = k;
                while (t--)
                {
                    j %= code.size();
                    result[i] += code[j];
                    j++;
                }
            }
        }

        else
        {
            for (int i = code.size() - 1; i >= 0; --i)
            {
                result[i] = 0;
                int j = i - 1;

                int t = -k;
                while (t--)
                {
                    if (j < 0)
                        j += code.size();

                    result[i] += code[j];
                    j--;
                }
            }
        }

        return result;
    }
};