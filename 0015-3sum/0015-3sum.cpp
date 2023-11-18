class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        set<vector<int>> ansSet;
        
        // nums is sorted so we can iterate like this
        for(int left = 0; left <= N-3; left++){
            int mid = left+1, right = N-1;
            while(mid < right){
                if(nums[left] + nums[mid] + nums[right] == 0){
                    ansSet.insert({nums[left], nums[mid], nums[right]});
                    // problem statement: the solution set must not contain duplicate triplets
                    // so even if nums[mid+1] + nums[right] equals nums[mid] + nums[right],
                    // we still skip this combination
                    mid++; right--;
                }else if(nums[left] + nums[mid] + nums[right] < 0){
                    // to make the sum larger(nums is sorted)
                    mid++;
                }else{
                    right--;
                }
            }
        }

        vector<vector<int>> ans(ansSet.begin(), ansSet.end());
        
        return ans;
    }
};