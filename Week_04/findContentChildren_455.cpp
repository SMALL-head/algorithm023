class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0, biscuit = s.size() - 1, child = g.size() - 1;
        while (child >= 0 && biscuit >= 0)
        {
            if (s[biscuit] >= g[child])
            {
                ++count;//满足条件，满足条件数量加一
                --child; //下一个孩子
                --biscuit; //分掉饼干
            }
            else
            {
                --child; //下一个胃口更小的孩子
            }
        }
        return count;
    }
};