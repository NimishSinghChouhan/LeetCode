class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector(n+1, false));
        
        //base case: both empty
        dp[m][n] = true;
        /*
        dp[i][n] is always false for i not equal to m,
        because at that time, s is not empty and p is empty
        */
        
        for(int i = m; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                bool first_match = (i < m) && (p[j] == s[i] || p[j] == '?' || p[j] == '*');
                
                if(p[j] == '*'){
                    dp[i][j] = (first_match && dp[i+1][j]) || dp[i][j+1];
                }else{
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        
        return dp[0][0];
    }
};