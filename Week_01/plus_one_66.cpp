//solution with recursion. Correct!
class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        recursion(digits, digits.size()-1);
        return digits;
    }
    void recursion(vector<int> &digits, int k)
    {
        if(++digits[k] < 10) //不进位情况
            return;
        else if(k == 0)
        {//处理首位进位情况
            digits[k] = 0;
            digits.insert(digits.begin(), 1);
            return;
        }
        else
        {//正常进位情况
            digits[k] = 0;
            recursion(digits, k-1);
        }
    }
};

//non recursion
class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            //某一位不进位直接结束循环
            if(++digits[i] < 10)
                break;
            //否则这一位变成0(因为是+1，所以进位只可能是10变成0)
            digits[i] = 0;
            //如果处理到首位进位，那么插1在最前面
            if(!i)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};