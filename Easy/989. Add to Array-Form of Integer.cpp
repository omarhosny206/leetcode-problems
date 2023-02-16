
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> result;
        int carry = 0;

        for (int i = num.size() - 1; i >= 0; --i)
        {
            int sum = carry + num[i];

            if (k > 0)
            {
                sum += (k % 10);
                k /= 10;
            }

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        while (k > 0)
        {
            int sum = carry + (k % 10);
            k /= 10;

            result.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0)
            result.push_back(carry);

        reverse(result.begin(), result.end());
        return result;
    }
};