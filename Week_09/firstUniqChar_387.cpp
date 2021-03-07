class Solution {
public:
    int firstUniqChar(string s) {
        //必然是On时间复杂度
        vector<int> vec(26, 0);
        int n = s.length();
        for (const auto &c : s)
        {
            vec[c-'a']++;
        }
        for (int i = 0; i < n; ++i)
        {
            if (vec[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};