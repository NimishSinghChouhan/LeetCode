class Solution {
public:
    int n;
    
    void backtrack(vector<int>& used, int r, 
                   vector<string>& cur, vector<vector<string>>& ans){
        if(r == n){
            ans.push_back(cur);
        }else{
            for(int c = 0; c < n; ++c){
                if(!used[c] && !used[n+r-c+n-1] && !used[n+2*n-1+r+c]){
                    cur[r][c] = 'Q';
                    used[c] = used[n+r-c+n-1] = used[n+2*n-1+r+c] = true;
                    
                    backtrack(used, r+1, cur, ans);
                    
                    used[c] = used[n+r-c+n-1] = used[n+2*n-1+r+c] = false;
                    cur[r][c] = '.';
                }
            }
        }
    };
    
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> cur(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<int> used(n + 2*n-1 + 2*n-1, false);
        
        backtrack(used, 0, cur, ans);
        
        return ans;
    }
};