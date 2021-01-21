class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> hash;
        for (const auto &i : bills)
        {//对每一个数字遍历
            if (!bill_func(hash, i)) return false;//贪心策略判断找零，若能找零，bill_func返回true;else返回false
                        
            ++hash[i]; //如果能找零，哈希表这个价位硬币增加一个
        }
        return true; //若没有硬币不可找零，那么就返回true
    }

    bool bill_func(unordered_map<int, int> &hash, int i)
    {
        for (const auto &each_pair : hash)
        {
            if (each_pair.second < 0) return false;
        }
        if (i == 5) return true;
        if (i >= 15 && hash[10] > 0)
        {
            --hash[10];
            return bill_func(hash, i - 10);
        }
        else 
        {
    //此处包括了两种情况：第一种是i小于15，此时不应该用10找零；第二种是面值10元没有了，此时不应该用10找零
            --hash[5];
            return bill_func(hash, i - 5);
        }
        
        
    }
};