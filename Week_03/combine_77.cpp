class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec, cur;
        for(int i = 1; i <= n; ++i)
        {
            vec.push_back(i);
        }
        backtrace(vec, cur, 0, k);
        return ret;
    }
    void backtrace(vector<int> &nums, vector<int> &cur, int n, int k)
    {
        if (k == 0)
        {
            ret.push_back(cur);
            return;
        }
        for(int i = n; i < nums.size(); ++i)
        {
            cur.push_back(nums[i]);
            backtrace(nums, cur, i + 1, k - 1);
            cur.pop_back();
        }
    }
private:
    vector<vector<int>> ret;
};