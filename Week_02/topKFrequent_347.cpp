class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashtable;
        vector<int> ret;
        for (int i : nums)
        {
            hashtable[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>> > pq;
        for (auto &each_one : hashtable)
        {
            pq.push({each_one.second, each_one.first});
        }
        while (k-- > 0)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};