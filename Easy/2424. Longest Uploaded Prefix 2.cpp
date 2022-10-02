// https://leetcode.com/problems/longest-uploaded-prefix/

class LUPrefix
{
    int position = 0;
    vector<int> values;

public:
    LUPrefix(int n)
    {
        values = vector<int>(n + 1);
    }

    void upload(int video)
    {
        values[video] = 1;

        while (position + 1 < values.size() && values[position + 1])
            position++;
    }

    int longest()
    {
        return position;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */