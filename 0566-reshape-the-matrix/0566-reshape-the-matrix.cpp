class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r*c!=nums.size()*nums[0].size()){
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        int idx = 0;
        
        for(vector<int> v : nums){
            for(int e : v){
                ans[idx/c][idx%c] = e;
                idx++;
            }
        }
        return ans;
    }
};