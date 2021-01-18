// https://leetcode.com/problems/design-an-ordered-stream/

class OrderedStream
{
    vector<string> stream;
    int currentOrder;

public:
    OrderedStream(int n)
    {
        stream = vector<string>(n + 1, "x");
        currentOrder = 1;
    }

    vector<string> insert(int id, string value)
    {
        vector<string> result;
        stream[id] = value;
        int i = currentOrder;

        while (i < stream.size() && stream[i] != "x")
        {
            result.push_back(stream[i]);
            i++;
        }

        currentOrder = i;
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */