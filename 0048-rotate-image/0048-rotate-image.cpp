class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n-1-i; ++i){
            swap(matrix[i], matrix[n-1-i]);
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};