// https://leetcode.com/problems/flatten-nested-list-iterator/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
    queue<int> result;

public:
    void dfs(vector<NestedInteger> &nestedList)
    {
        for (auto element : nestedList)
        {
            if (element.isInteger())
                result.push(element.getInteger());

            else
                dfs(element.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        dfs(nestedList);
    }

    int next()
    {
        int value = result.front();
        result.pop();

        return value;
    }

    bool hasNext()
    {
        return !result.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */