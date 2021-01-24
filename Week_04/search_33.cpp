class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, result;
        while (left <= right)
        {
            int mid = (left & right) + ((left ^ right) >> 1);
            if (nums[mid] == target) return mid;//找到直接返回索引下标
            if (nums[left] <= nums[mid] && target >= nums[left] && nums[mid] >= target)
            {//前半部分有序且target位于前半部分中
                right = mid - 1;
            }
            else if (nums[left] <= nums[mid])
            {//前半部分有序，但是target不在前半部分（只能在后半部分）
                left = mid + 1;
            }
            else if (nums[left] >= nums[mid] && target >= nums[mid] && nums[right] >= target)
            {//前半部分无序，但是查找值在有序部分
                left = mid+1;
            }
            else
            {//前半部分无序，查找值在前半部分
                right = mid - 1;
            }
        }
        return -1;
    }
};