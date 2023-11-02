class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        for(int i = 0; i < K; i++){
            //every time reverse the smallest element
            vector<int>::iterator it = min_element(A.begin(), A.end());
            *it = -*it;
        }
        
        return accumulate(A.begin(), A.end(), 0);
    }
};