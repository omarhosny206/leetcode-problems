class DataStream
{
    vector<int> values;
    int value;
    int k;
    int i = 0;
    int j = 0;
    int counter = 0;

public:
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
    }

    bool consec(int num)
    {
        bool result = false;

        if (num == value)
            counter++;

        values.push_back(num);

        int windowSize = j - i + 1;

        if (windowSize == k)
        {
            if (counter == k)
                result = true;

            if (values[i] == value)
                counter--;

            i++;
        }

        j++;

        return result;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */