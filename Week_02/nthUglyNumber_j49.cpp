class Solution {
public:
    int nthUglyNumber(int n) {
        int dp1 = 0, dp2 = 0, dp3 = 0;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            dp[i] = min(min(dp[dp1] * 2, dp[dp2] * 3), dp[dp3] * 5);
            if (dp[dp1] * 2 == dp[i]) dp1++;
            if (dp[dp2] * 3 == dp[i]) dp2++;
            if (dp[dp3] * 5 == dp[i]) dp3++;
        }
        return dp[n-1];

    }
};