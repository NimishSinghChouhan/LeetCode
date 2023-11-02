class Solution {
public:
    bool isPowerOfThree(int n) {
        int max_power_of_3 = pow(3, int(log(INT_MAX)/log(3)));
        //if n can divide max_power_of_3, it's power of 3
        return n > 0 && max_power_of_3 % n == 0;
    }
};