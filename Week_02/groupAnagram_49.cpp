class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hashtable;
        int nums = 0;
        for(auto &s : strs)
        {
            string copy_s = s;
            sort(copy_s.begin(), copy_s.end());
            if(hashtable.find(copy_s) == hashtable.end())
            {
                ret.resize(nums + 1);
                hashtable[copy_s] = nums++;
            }
            int index = hashtable[copy_s];
            ret[index].emplace_back(s);
        }
        return ret;
    }
    
private:
    vector<vector<string>> ret;
};