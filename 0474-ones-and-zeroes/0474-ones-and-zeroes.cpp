class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //bounded backpack problem with 2-dimensional constraint
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m+1, vector(n+1, 0)));
        
        for(int i = 0; i < strs.size(); i++){
            //the cost of char '0'
            int cm = count(strs[i].begin(), strs[i].end(), '0');
            //the cost of char '1'
            int cn = strs[i].size() - cm;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(i == 0){
                        dp[i%2][j][k] = (j >= cm && k >= cn);
                    }else{
                        dp[i%2][j][k] = max(dp[(i-1)%2][j][k], (j >= cm && k >= cn) ? 1 + dp[(i-1)%2][j-cm][k-cn] : 0);
                    }
                    // cout << i << ", " << j << ", " << k << " : " << dp[i%2][j][k] << endl;
                }
            }
        }
        
        return dp[(strs.size()-1)%2][m][n];
    }
};