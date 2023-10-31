class Solution {
public:
    vector<vector<int>> memo;
    
    int lengthOfLIS(vector<int>& nums, int prev, int cur) {
        /*
        nums[cur] is the element we consider to append,
        it cannot be out of the range of nums
        */
        if(cur == nums.size()) return 0;
        if(memo[prev+1][cur] != -1) return memo[prev+1][cur];
        int taken = 0;
        //we may append current element into sequence
        /*
        initial state: prev is -1, and cur = 0,
        that means we are considering the 0th element,
        and the 0th element is always ok to be appended to the empty sequence
        */
        if(prev < 0 || nums[cur] > nums[prev]){
            taken = 1 + lengthOfLIS(nums, cur, cur+1);
        }
        //skip current element
        int nottaken = lengthOfLIS(nums, prev, cur+1);
        // cout << prev << ", " << cur << " : " << taken << ", " << nottaken << endl;
        memo[prev+1][cur] = max(taken, nottaken);
        return memo[prev+1][cur];
    }
    
    int lengthOfLIS(vector<int>& nums){
        /*
        padding ahead,
        because prev may be -1
        */
        int n = nums.size();
        memo = vector<vector<int>>(n+1, vector(n, -1));
        return lengthOfLIS(nums, -1, 0);
    }
};