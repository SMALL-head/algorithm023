class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); ++i)
        {//让i处在第一个不为0的地方，j始终处于第一个0，然后交换
            if(nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                ++j;
            }
        }
    }
};