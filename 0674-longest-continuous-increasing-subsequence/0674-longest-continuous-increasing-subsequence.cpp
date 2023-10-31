class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int l = 1;
        int ans = INT_MIN;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] <= 0){
                ans = max(ans, l);
                l = 1;
            }else{
                l++;
            }
            // cout << l << endl;
        }
        ans = max(ans, l);
        // cout << endl;
        
        return ans;
    }
};
