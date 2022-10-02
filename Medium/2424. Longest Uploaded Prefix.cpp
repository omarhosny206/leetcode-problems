// https://leetcode.com/problems/longest-uploaded-prefix/

class LUPrefix
{
    int result = 0;
    vector<int> values;

public:
    LUPrefix(int n)
    {
        values = vector<int>(n + 1);
        values[0] = 0;
    }

    void upload(int video)
    {
        values[video] = 1;

        if (values[video - 1] == video - 1)
        {
            values[video] = video;
            int i = video + 1;

            while (i < values.size() && values[i] != 0)
            {
                values[i] = i;
                i++;
            }

            result = max(result, values[i - 1]);
        }
    }

    int longest()
    {
        return result;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */