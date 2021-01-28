class Solution {
public:
    int numDecodings(string s) {
        string::size_type n = s.length();
        vector<int> dp(n);
        dp[0] = (s[0] == '0' ? 0 : 1);
        if (n == 1) return dp[0];
        string sub_s = s.substr(0,2);
        if (s[0] == '0' || (stoi(sub_s) > 26 && s[1] == '0')) dp[1] = 0;
        else if (stoi(sub_s) <= 26 && sub_s[1] != '0') dp[1] = 2;
        else dp[1] = 1;
        for (int i = 2; i < n; ++i)
        {
            string tmp = s.substr(i-1, 2);
            dp[i] = (s[i] != '0' ? dp[i-1] : 0) + (stoi(tmp) <= 26 && tmp[0] != '0' ? dp[i-2] : 0);
        }
        return dp[n-1];
    }
};