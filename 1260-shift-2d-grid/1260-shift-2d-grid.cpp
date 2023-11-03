class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                int new_j = (j + k)%n;
                int new_i = (i + (j + k)/n)%m;
                ans[new_i][new_j] = grid[i][j];
            }
        }
        
        return ans;
    }
};