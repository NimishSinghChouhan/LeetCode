class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        vector<vector<int>> inDegree(m, vector(n, 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(vector<int>& dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[i][j] < matrix[ni][nj]){
                        //we create an edge from smaller to larger
                        inDegree[ni][nj]++;
                    }
                }
            }
        }
        
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(inDegree[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        
        int ans = 0;
        
        while(!q.empty()){
            int levelCount = q.size();
            //visite current level
            while(levelCount-- > 0){
                vector<int> cur = q.front(); q.pop();
                int ci = cur[0], cj = cur[1];

                for(vector<int>& dir : dirs){
                    int ni = ci+dir[0];
                    int nj = cj+dir[1];

                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[ci][cj] && --inDegree[ni][nj] == 0){
                        //if there's an edge from (ci,cj) to (ni,nj)
                        q.push({ni, nj});
                    }
                }
            }
            ans++;
        }
        
        return ans;
    }
};