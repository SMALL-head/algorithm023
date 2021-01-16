class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return ret;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), 0);
        backtrace(nums,  nums.size(), used);
        return ret;
    }
    void backtrace(vector<int> &nums, int len, vector<bool> &used)
    {
        if (path.size() == len)
        {
            ret.push_back(path);
            return;
        }
        for (int i = 0; i < len; ++i)
        {
            if (i != 0 && nums[i] == nums[i-1] && used[i-1] == 1) continue;
            if (used[i] == 1) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            backtrace(nums, len, used);
            used[i] = 0;
            path.pop_back();
        }
    }
private:
    vector<vector<int>> ret;
    vector<int> path;
};