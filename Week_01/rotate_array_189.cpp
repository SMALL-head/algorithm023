class Solution1
{//correct! But TLE! -_-||
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return;
        k = k % nums.size();
        int end_flag = nums.size() - 1;
        for (int i = end_flag - k; i >= 0; --i)
        {
            int copy_i = i;
            for (int j = i + 1; j <= end_flag; ++j, ++copy_i)
            {
                swap(nums[copy_i], nums[j]);
            }
            --end_flag;
        }
    }
};


class Solution2
{//correct! But use (n-k) sizeof(nums[0]) 's space!
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return;
        k = k % nums.size();
        int new_begin = nums.size() - k;
        for (int i = 0; i < new_begin; ++i)
        {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + new_begin);
    }
};