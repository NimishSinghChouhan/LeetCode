class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<int> tmp;
        vector<vector<int>> B;
        for(int r = 0; r < A[0].size(); r++){
            tmp.clear();
            for(int c = 0; c < A.size(); c++){
                tmp.push_back(A[c][r]);
            }
            B.push_back(tmp);
        }
        return B;
    }
};