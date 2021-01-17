// https://leetcode.com/problems/mini-parser/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        stack<NestedInteger> nestedStack;
        nestedStack.push(NestedInteger());

        auto it = s.begin();

        while (it != s.end())
        {
            char c = *it;
            if (isNumber(c))
            {
                auto it2 = find_if_not(it, s.end(), isNumber);
                int val = stoi(string(it, it2));
                nestedStack.top().add(NestedInteger(val));
                it = it2;
            }

            else
            {
                if (c == '[')
                    nestedStack.push(NestedInteger());

                else if (c == ']')
                {
                    NestedInteger ni = nestedStack.top();
                    nestedStack.pop();
                    nestedStack.top().add(ni);
                }
                it++;
            }
        }

        NestedInteger result = nestedStack.top().getList().front();
        return result;
    }

    static bool isNumber(char c)
    {
        return c == '-' || isdigit(c);
    }
};