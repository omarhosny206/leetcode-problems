// https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator
{
    queue<string> combinations;
    string combString;

public:
    CombinationIterator(string characters, int combinationLength)
    {
        combString = characters;
        int n = characters.length();
        generateCombinations(n, combinationLength, 1, n, "");
    }

    string next()
    {
        string front = combinations.front();
        combinations.pop();
        return front;
    }

    bool hasNext()
    {
        return !combinations.empty();
    }

    void generateCombinations(int n, int combinationLength, int start, int &limit, string t_comb)
    {
        if (combinationLength == 0)
        {
            combinations.push(t_comb);
            return;
        }

        if (n == 0)
            return;

        for (int i = start; i <= limit - combinationLength + 1; i++)
            generateCombinations(n - 1, combinationLength - 1, i + 1, limit, t_comb + combString[i - 1]);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */