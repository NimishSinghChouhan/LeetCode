class Solution {
public:
    int bulbSwitch(int n) {
        /*
        we want to find how many i in the range [1...n] whose
        divisor count is odd.
        A number's divisor count is odd iff it's square.
        So we want to find out how many i in the range [1...n] is square.
        And the count of square root in the range [1...sqrt(n)] is same as the count of square in the range[1...n],
        so we can just give sqrt(n) as our answer
        */
        return sqrt(n);
    }
};