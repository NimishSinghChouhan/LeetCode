class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int k = 2;
        
        for(int fast = 0; fast < n; ++fast){
            if(slow < k || nums[fast] != nums[slow-k]){
                /*
                only update nums[slow] when 
                there are < k nums[fast] in the new array
                */
                nums[slow++] = nums[fast];
            }
        }
        
        return slow;
    }
};