class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return true;
        int k = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};