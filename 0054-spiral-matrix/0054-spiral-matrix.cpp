class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        if(n == 0) return {};
        
        int r1 = 0, r2 = m-1, c1 = 0, c2 = n-1;
        vector<int> ans;
        
        while(r1 <= r2 && c1 <= c2){
            //iterate through one layer
            for(int c = c1; c <= c2; ++c) ans.push_back(matrix[r1][c]);
            for(int r = r1+1; r <= r2; ++r) ans.push_back(matrix[r][c2]);
            if(r1 < r2 && c1 < c2){
                //if this layer is not one row or one column
                for(int c = c2-1; c >= c1; --c) ans.push_back(matrix[r2][c]);
                for(int r = r2-1; r >= r1+1; --r) ans.push_back(matrix[r][c1]);
            }
            
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        
        return ans;
    }
};