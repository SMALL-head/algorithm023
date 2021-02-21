class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size(), path = 0;
        queue<string> q;
        unordered_set<string> wordset(wordList.begin(), wordList.end()); //转化成哈希表，提高查找效率
        if (wordset.find(endWord) == wordset.end()) return 0; //无法转化
        unordered_map<string, bool> is_visited;
        is_visited[beginWord] = 1;
        q.push(beginWord);
        ++path;

        while (!q.empty())
        {
            int qsize = q.size();
            bool can_add = 0;
            for (int i = 0; i < qsize; ++i)
            {
                int tmpsz = q.front().size();
                for (int j = 0; j < tmpsz; ++j)
                {
                    string tmp = q.front();
                    for (int alpha = 0; alpha < 26; ++alpha)
                    {
                        tmp[j] = 'a'+ alpha;
                        if (tmp == endWord) return path + 1;
                        if (is_visited[tmp] == 0 && wordset.find(tmp) != wordset.end())
                        {
                            is_visited[tmp] = 1;
                            q.push(tmp);
                            can_add = 1;
                        }    
                    }   
                }
                q.pop();
            }
            if (can_add) ++path;
        } 
        return 0;   
    }
};