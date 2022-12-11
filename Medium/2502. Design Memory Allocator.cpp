// https://leetcode.com/problems/design-memory-allocator/

class Allocator
{
    vector<int> values;
    vector<int> left;
    vector<int> right;

public:
    Allocator(int n)
    {
        values = vector<int>(n);
        left = vector<int>(n);
        right = vector<int>(n);

        update();
    }

    int allocate(int size, int mID)
    {
        int result = -1;

        for (int i = 0; i < values.size(); ++i)
        {
            if (values[i] == 0 && (left[i] + right[i] + 1) >= size)
            {
                result = i;

                for (int j = i; j < i + size; ++j)
                    values[j] = mID;

                break;
            }
        }

        if (result != -1)
            update();

        return result;
    }

    int free(int mID)
    {
        int counter = 0;

        for (int i = 0; i < values.size(); ++i)
        {
            if (values[i] == mID)
            {
                counter++;
                values[i] = 0;
            }
        }

        if (counter > 0)
            update();

        return counter;
    }

    void update()
    {
        int i = 0;
        while (i < left.size())
        {
            if (values[i] == 0)
                countLeftZeros(i);

            else
                i++;
        }

        i = values.size() - 1;
        while (i >= 0)
        {
            if (values[i] == 0)
                countRightZeros(i);

            else
                i--;
        }
    }

    void countLeftZeros(int &i)
    {
        int value = 0;

        while (i < left.size() && values[i] == 0)
        {
            left[i] = value;
            value++;
            i++;
        }
    }

    void countRightZeros(int &i)
    {
        int value = 0;

        while (i >= 0 && values[i] == 0)
        {
            right[i] = value;
            value++;
            i--;
        }
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */