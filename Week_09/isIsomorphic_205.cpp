class Solution {
public:
    bool isIsomorphic(const string &s, const string &t) {
        unordered_map<char, set<char>> hashtable1, hashtable2;
        for(int i = 0; i < s.size(); ++i)
        {
            hashtable1[s[i]].insert(t[i]);
            hashtable2[t[i]].insert(s[i]);
            if(hashtable1[s[i]].size() > 1 || hashtable2[t[i]].size() > 1)
                return false;
        }
        return true;
    }
};