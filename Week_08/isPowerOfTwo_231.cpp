class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) return false;
        return (n > 0) && (n & (n-1)) == 0;
    }
};