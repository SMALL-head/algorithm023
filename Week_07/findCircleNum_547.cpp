class DS_union{
public:
    DS_union(int n) {
        vec.assign(n, -1);
    }
    void combine(int a1, int a2)
    {
        if (a1 == a2) return;
        int tmp = vec[a1] + vec[a2];
        if (vec[a1] < vec[a2])
        {//a1多,a2少
            vec[a1] = tmp;
            vec[a2] = a1;
        }
        else
        {
            vec[a2] = tmp;
            vec[a1] = a2;
        }
    }
    int find(int x)
    {
        while (vec[x] >= 0) x = vec[x];
        return x;
    }
    int result() {
        //统计连通分量个数
        int ret = 0;
        for (const int &e : vec)
        {
            if (e < 0) ++ret;
        }
        return ret;
    }
private:
    vector<int> vec;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        if (!m) return 0;
        int n = isConnected[0].size(); 
        DS_union ds_set(m);
        for (int i = 0; i < m; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int root1 = ds_set.find(i);
                int root2 = ds_set.find(j);
                if (isConnected[i][j])
                    ds_set.combine(root1, root2);
            }
        }
        return ds_set.result();
        
    }
};