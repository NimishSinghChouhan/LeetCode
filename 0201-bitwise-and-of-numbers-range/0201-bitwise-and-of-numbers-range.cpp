class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n > m){
            /*
            suppose a >= b
            the result of a & b must <= min(a, b) = b,
            so we can skip numbers between b and (a&b)
            */
            n &= (n-1);
        }
        return n & m;
    }
};