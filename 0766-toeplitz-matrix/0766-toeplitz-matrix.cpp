class Solution {
public:
    bool isDiagAllSame(vector<vector<int>>& matrix, int i, int j){
        //i, j: a point to identity a diagonal
        int base = matrix[i][j];
        bool allSame = true;
        
        i++;
        j++;
        
        while(i<matrix.size() && j<matrix[0].size()){
            if(matrix[i][j]!=base){
                allSame = false;
            }
            i++;
            j++;
        }
        return allSame;
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        /*
        for M x N matrix
        (M-1, 0) -> (M-2, 0) -> ... -> (0, 0)
        -> (0, 1) -> (0, 2) -> (0, 3) -> (0, N-1)
        */
        for(int i = matrix.size()-1; i>=0; i--){
            if(!isDiagAllSame(matrix, i, 0)){
                return false;
            }
        }
        for(int j = 1; j<matrix[0].size(); j++){
            if(!isDiagAllSame(matrix, 0, j)){
                return false;
            }
        }
        return true;
    }
};