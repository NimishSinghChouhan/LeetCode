class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n <= 1) return 0;
        
        vector<int> dp(n);
        iota(dp.begin(), dp.end(), 0);
        
        int w, choice;
        //start from center = 1, because dp[0] is always 0
        for(int c = 1; c < n; c++){
            w = 0;
            //odd
            //c-w: left, c+w: right
            while(c-w >= 0 && c+w < n && s[c-w] == s[c+w]){
                //c-w-1: left-1
                choice = (c-w-1 >= 0) ? dp[c-w-1]+1 : 0;
                //update dp[end], not dp[center]!
                dp[c+w] = min(dp[c+w], choice);
                w++;
            }
            
            //even
            w = 0;
            
            /*
            since we start from c = 1,
            we need to take care of s[0],
            so we set left = c-w-1 and right = c+w,
            not left = c-w and right = c+w+1
            */
            while(c-w-1 >= 0 && c+w < n && s[c-w-1] == s[c+w]){
                choice = (c-w-1-1 >= 0) ? dp[c-w-1-1]+1 : 0;
                dp[c+w] = min(dp[c+w], choice);
                w++;
            }
        }
        
        return dp[n-1];
    }
};