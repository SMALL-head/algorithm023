class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int p = 0;
        int q = 1;
        while(q < nums.size())
        {
            if(nums[q] == nums[p])
            {
                ++q;
            }
            else
            {
                nums[p+1] = nums[q];
                ++p;
                ++q;
            }
        }
        return p+1;
    }
};