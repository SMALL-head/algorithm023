class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int ret = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = (matrix[i][0] == '1' ? 1 : 0);
            ret = max(dp[i][0], ret);
        }
        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = (matrix[0][j] == '1' ? 1 : 0);
            ret = max(dp[0][j], ret);
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    ret = max(ret, dp[i][j]);
                }
            }
        }
        return ret * ret;
    }
};