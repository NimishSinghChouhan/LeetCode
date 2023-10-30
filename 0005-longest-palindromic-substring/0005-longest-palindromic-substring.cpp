class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector(n, false));
        string ans;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                //susbstring: s[i...j]
                //length 1
                if(i == j){
                    dp[i][j] = true;
                }else if(i+1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
                
                if(dp[i][j] && j-i+1 > ans.size()){
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        
        return ans;
    }
};