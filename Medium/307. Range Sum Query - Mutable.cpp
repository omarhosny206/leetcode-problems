// https://leetcode.com/problems/range-sum-query-mutable/

class segmentTree
{
public:
    int sum, start, end;
    segmentTree *left, *right;
    segmentTree(int start, int end)
    {
        this->start = start;
        this->end = end;
        this->left = nullptr;
        this->right = nullptr;
        this->sum = 0;
    }
};

class NumArray
{
public:
    segmentTree *root = nullptr;

    segmentTree *buildTree(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        else
        {
            segmentTree *ret = new segmentTree(start, end);

            if (start == end)
                ret->sum = nums[start];

            else
            {
                int middle = start + (end - start) / 2;
                ret->left = buildTree(nums, start, middle);
                ret->right = buildTree(nums, middle + 1, end);
                ret->sum = ret->left->sum + ret->right->sum;
            }

            return ret;
        }
    }

    NumArray(vector<int> &nums)
    {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val)
    {
        update(root, i, val);
    }

    void update(segmentTree *root, int pos, int val)
    {
        if (root->start == root->end)
            root->sum = val;

        else
        {
            int middle = root->start + (root->end - root->start) / 2;

            if (pos <= middle)
                update(root->left, pos, val);

            else
                update(root->right, pos, val);

            root->sum = root->left->sum + root->right->sum;
        }
    }

    int sumRange(int i, int j)
    {
        return sumRange(root, i, j);
    }

    int sumRange(segmentTree *root, int start, int end)
    {
        if (root->end == end && root->start == start)
            return root->sum;

        else
        {
            int middle = root->start + (root->end - root->start) / 2;

            if (end <= middle)
                return sumRange(root->left, start, end);

            else if (start >= middle + 1)
                return sumRange(root->right, start, end);

            else
                return sumRange(root->right, middle + 1, end) + sumRange(root->left, start, middle);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */