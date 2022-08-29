
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int result = INT_MIN;
        vector<int> freq(fruits.size());

        int i = 0;
        int j = 0;
        int counter = 0;

        while (j < fruits.size())
        {
            if (++freq[fruits[j]] == 1)
                counter++;

            if (counter > 2)
            {
                while (counter > 2 && freq[fruits[i]]-- > 0)
                {
                    if (freq[fruits[i]] == 0)
                        counter--;

                    i++;
                }
            }

            int windowSize = j - i + 1;
            result = max(result, windowSize);

            j++;
        }

        return result;
    }
};