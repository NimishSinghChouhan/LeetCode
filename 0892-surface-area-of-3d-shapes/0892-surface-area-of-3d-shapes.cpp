class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int n = grid.size();
        int ans = 0;
        
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c]){
                    ans += 2;
                    for(pair<int, int> dir : dirs){
                        //nv : neighboring grid's value
                        int nr = r + dir.first;
                        int nc = c + dir.second;
                        int nv = 0;
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n)
                            nv = grid[nr][nc];
                        ans += max(grid[r][c] - nv, 0);
                    }
                }
            }
        }
        
        return ans;
    }
};