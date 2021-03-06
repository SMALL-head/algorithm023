<<<<<<< HEAD
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return ret;
        backtrace(nums, 0, nums.size());
        return ret;
    }
    void backtrace(vector<int> &nums, int first, int len)
    {
        if (first == len)
        {
            ret.push_back(nums);
            return;
        }
        
        for (int i = first; i < nums.size(); ++i)
        {
            swap(nums[i], nums[first]);
            backtrace(nums,first + 1, len);
            swap(nums[i], nums[first]);
        }
    }
private:
    vector<vector<int>> ret;
=======
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
            return ret;
        backtrace(nums, 0, nums.size());
        return ret;
    }
    void backtrace(vector<int> &nums, int first, int len)
    {
        if (first == len)
        {
            ret.push_back(nums);
            return;
        }
        
        for (int i = first; i < nums.size(); ++i)
        {
            swap(nums[i], nums[first]);
            backtrace(nums,first + 1, len);
            swap(nums[i], nums[first]);
        }
    }
private:
    vector<vector<int>> ret;
>>>>>>> 201d909a9383347be4a6f635db7f9764a4b39c5f
};