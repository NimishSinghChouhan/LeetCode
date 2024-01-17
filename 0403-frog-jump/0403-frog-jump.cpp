class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size() == 0) return true;
        set<int> sstones(stones.begin(), stones.end());
        stones = vector<int>(sstones.begin(), sstones.end());
        
        int goal = stones.back();
        
        int n = stones.size();
        
        /*
        dp[i][j]: at ith stone(i is for index, not position!), 
        (the index of i is 0-based),
        whether we can jump with distance j
        n+1: at position i, the maximum distance we can jump is i+1
        */
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        
        //base case: at position 0, we can jump 1 distance forward
        dp[0][1] = true;
        
        for(int end = 1; end < n; ++end){
            for(int start = 0; start < end; ++start){
                //start and end are index, here convert them into actual positions
                int dist = stones[end] - stones[start];
                if(dist >= n+1 || !dp[start][dist]) continue;
                if(end == n-1) return true;
                for(int ndist = dist-1; ndist <= dist+1; ndist++){
                    if(ndist <= 0) continue;
                    dp[end][ndist] = true;
                }
            }
        }
        
        return false;
    }
};