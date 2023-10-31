class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return vector<string>();
        int start;
        vector<string> ans;
        for(int i = 0; i < n; i++){
            start = nums[i];
            while(i+1 < n && nums[i] != INT_MAX && nums[i+1] == nums[i]+1){
                i++;
            }
            //now i is the index of the end of the interval
            
            if(start == nums[i])
                ans.push_back(to_string(start));
            else
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
        }
        
        return ans;
    }
};