
class SummaryRanges
{
private:
    set<int> values;

public:
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        values.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> result;
        int current = -1;
        int temp = -1;

        for (const auto &value : values)
        {
            if (current == -1)
            {
                temp = value;
                current = value;
            }

            else if (current + 1 == value)
                current++;

            else
            {
                result.push_back({temp, current});
                temp = value;
                current = value;
            }
        }

        result.push_back({temp, current});
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */