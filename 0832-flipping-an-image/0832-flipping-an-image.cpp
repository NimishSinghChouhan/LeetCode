class Solution {
//the keyword 'static' fixes "invalid use of non-static member function 'int Solution::op_inverse(int)'"
static int op_inverse (int i) { return 1-i; }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++){
            reverse(A[i].begin(),A[i].end());
            transform (A[i].begin(), A[i].end(), A[i].begin(), op_inverse);
        }
        return A;
    }
};