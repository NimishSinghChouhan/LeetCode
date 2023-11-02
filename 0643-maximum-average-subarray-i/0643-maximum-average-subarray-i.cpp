class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum;
        double cursum = 0;
        
        for(int i = 0; i < k; i++) cursum += nums[i];
        
        maxsum = cursum;
        
        for(int i = 1; i <= nums.size() - k; i++){
            cursum = cursum - nums[i-1] + nums[i+k-1];
            maxsum = max(maxsum, cursum);
        }
        
        return maxsum/k;
    }
};