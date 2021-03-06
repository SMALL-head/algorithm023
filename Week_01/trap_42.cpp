class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
        {
            return 0;
        }
        stack<int> stk;
        int ret = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            while(!stk.empty() && height[stk.top()] < height[i])
            {//curIdx是接雨水的待计算的容器底部，与之后会计算的两端高度一起计算这部分的容量
                int curIdx = stk.top();
                stk.pop();
                while(!stk.empty() && height[stk.top()] == height[curIdx])
                {
                    stk.pop();
                }
            
                if(!stk.empty())
                {
                    int stkTop = stk.top();
                    ret += (i - stkTop - 1) * (min(height[i], height[stkTop]) - height[curIdx]);
                }
            }
            stk.push(i);
        }
        return ret;
    }   
};