
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs;
    vector<int> cur;
    
    void changeNeighbor(vector<vector<char>>& board, int i, int j, char src, char dst){
        queue<vector<int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while(!q.empty()){
            cur = q.front(); q.pop();
            board[cur[0]][cur[1]] = dst;

            for(vector<int>& dir : dirs){
                int ni = cur[0] + dir[0];
                int nj = cur[1] + dir[1];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O' && !visited[ni][nj]){
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    };
    
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0) return;
        n = board[0].size();
        if(n == 0) return;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        dirs = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        
        for(int j = 0; j < n; ++j){
            for(int i : {0, m-1}){
                if(board[i][j] == 'O' && !visited[i][j]){
                    changeNeighbor(board, i, j, 'O', '1');
                }
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j : {0, n-1}){
                if(board[i][j] == 'O' && !visited[i][j]){
                    changeNeighbor(board, i, j, 'O', '1');
                }
            }
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};