class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int N = nums.size();
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        //width: the valid width of range of balloons able to be burst
        for(int width = 1; width <= N-2; width++){
            for(int left = 0; left + width + 1 < N; left++){
                //left, right: the outer element of valid range
                int right = left + width + 1;
                //split is the position of last balloon to burst
                //its valid range is (left, right)
                for(int split = left+1; split <= right-1; split++){
                    dp[left][right] = max(dp[left][right],
                        nums[left]*nums[split]*nums[right] + 
                        dp[left][split] +
                        dp[split][right]);
                }
            }
        }
        
        return dp[0][N-1];
    }
};