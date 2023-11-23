class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        vector<long long int> row(n+1, 0LL);
        
        row[1] = 1;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 && j == 1) continue;
                row[j] = (obstacleGrid[i-1][j-1] == 1) ? 0 : (row[j] + row[j-1]);
            }
        }
        
        return row[n];
    }
};