class Solution {
public:
    bool isPerfectSquare(int num) {
        long long x = num;
        while(x * x > num){
            x = (x + num/x) >> 1;
        }
        return x*x == num;
    }
};