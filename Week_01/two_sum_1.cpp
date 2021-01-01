//Brute-Force
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }
        return vector<int>();
    }
};

//hashtable
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            hashtable[nums[i]] = i + 1; //让下标均大于0
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (hashtable[target - nums[i]] && hashtable[target - nums[i]] - 1 != i)
            {//上述if需要判断下标是否一样，因为题目要求不能使用相同的数字
                return vector<int>{hashtable[target - nums[i]] - 1, i};
            }
        }
        return vector<int>();
    }
};
