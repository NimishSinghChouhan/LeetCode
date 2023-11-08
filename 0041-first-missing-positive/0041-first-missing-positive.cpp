class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        /*
        if nums is [1,n], 
        then the first missing positive number is n+1,
        otherwise there's some number in [`,n] missing in nums,
        so the first missing positive number is in [1,n].
        To summary, first missing positive number's range
        should be in 1 to n+1.
        */
        for(int i = 0; i < n; ++i){
            /*
            swap every number in [1,n] to its correct position
            for example, if we find a 5,
            we should put it into position 4
            
            nums[i] should be put in the 'nums[i]-1'th position
            */
            /*
            it's "while", not "if"!!!
            that is because we also want to put 
            the swapped element in the right place
            for the testcase [-1,4,3,1],
            it will become [-1,1,3,4] -> [1,-1,3,4]
            */
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
                // for(int num : nums){
                //     cout << num << " ";
                // }
                // cout << endl;
            }
        }
        
        for(int i = 0; i < n; ++i){
            /*
            the number i+1 is not in its correct position,
            so it must be missing
            */
            if(nums[i] != i+1){
                return i+1;
            }
        }
        
        return n+1;
    }
};