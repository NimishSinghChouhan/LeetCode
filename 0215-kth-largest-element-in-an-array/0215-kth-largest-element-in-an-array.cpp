class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int x=0;
        int size =nums.size();
        x=nums[size-k];
        return x;
    }
};