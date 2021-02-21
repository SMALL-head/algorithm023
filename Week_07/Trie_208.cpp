class Trie
{
public:
    Trie()
    {
        next.assign(26, 0);
        word = "";
    }

    void insert(const string &s)
    {
        Trie *tmp = this;
        for (const char c : s)
        {
            if (tmp->next[c - 'a'] == nullptr)
            {
                tmp->next[c - 'a'] = new Trie();
            }
            tmp = tmp->next[c - 'a'];
        }
        tmp->word = s;
    }

    bool search(const string &s)
    {
        Trie *tmp = this;
        for (const char &c : s)
        {
            if (tmp->next[c-'a'] != nullptr)
                tmp = tmp->next[c - 'a'];
            else return false;
        }
        return tmp->word != "";
    }
    bool startsWith(string prefix)
    {
        Trie *tmp = this;
        for (const char &c : prefix)
        {
            if (tmp->next[c - 'a'] != nullptr)
                tmp = tmp->next[c - 'a'];
            else
                return false;
        }
        return true;
    }
public:
    string word;//把之前的bool标记更改为string，可以提供更为方便的功能
    vector<Trie *> next; //这里使用指针主要是为了上面构造函数
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */