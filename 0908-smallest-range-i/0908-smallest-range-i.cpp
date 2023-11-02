class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        return max(*max_element(A.begin(), A.end())-*min_element(A.begin(), A.end())-2*K,0);
    }
};