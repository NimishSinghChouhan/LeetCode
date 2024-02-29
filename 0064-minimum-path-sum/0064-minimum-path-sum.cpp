class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //INT_MAX means invalid
                int top = (i-1>=0) ? grid[i-1][j] : INT_MAX;
                int left = (j-1>=0) ? grid[i][j-1] : INT_MAX;
                grid[i][j] += (min(top, left) == INT_MAX)?0:min(top, left);
                // cout << grid[i][j] << " ";
            }
            // cout << endl;
        }
        
        return grid[m-1][n-1];
    }
};