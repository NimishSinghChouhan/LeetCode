class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int N = grid.size();
        for(int i = 0; i < N; i++){
            int rowBest = 0;
            int colBest = 0;
            for(int j = 0; j < N; j++){
                if(grid[i][j]>0) ans++;
                rowBest = max(rowBest, grid[i][j]);
                //since grid is a square, so we can do this
                colBest = max(colBest, grid[j][i]);
            }
            ans+=rowBest+colBest;
        }
        return ans;
    }
};