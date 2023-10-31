class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //Method 1(TLE)
        /**
        if(nums.size()==0){
            return vector<int>();
        }
        int _min = nums[0], _max = nums[0];
        vector<int> ans;
        for(int num : nums){
            if(num < _min){
                for(int i = num+1; i < _min; i++){
                    ans.push_back(i);
                }
                _min = num;
            }
            
            if(num > _max){
                for(int i = _max+1; i < num; i++){
                    ans.push_back(i);
                }
                _max = num;
            }
            
            vector<int>::iterator it = find(ans.begin(), ans.end(), num);
            if(it!=ans.end()){
                ans.erase(it);
            }
        }
        **/
        
        //Method 2(TLE)
        /**
        if(nums.size()==0){
            return vector<int>();
        }
        //if nums' values won't cover the range of [1,n]
        for(int i = 1; i < _min; i++){
            ans.push_back(i);
        }
        
        for(int i = nums.size(); i > _max; i--){
            ans.push_back(i);
        }
        
        vector<int> ans(nums.size());
        iota(ans.begin(), ans.end(), 1); //1 is the starting number
        
        for(int num : nums){
            ans.erase(remove(ans.begin(), ans.end(), num), ans.end());
        }
        **/
        
        //Method 3
        /**
        if(nums.size()==0){
            return vector<int>();
        }
        
        vector<bool> exist(nums.size(), false);
        for(int num : nums){
            exist[num-1] = true;
        }
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(exist[i]==false){
                ans.push_back(i+1);
            }
        }
        **/
        
        //Method 4(In-place)
        //https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/92956/Java-accepted-simple-solution
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            //after we seen nums[i], we make the position of nums[i]-1 negative 
            int val = abs(nums[i])-1;
            if(nums[val]>0){
                //we have seen val+1 in nums
                nums[val] *= -1;
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>0) ans.push_back(i+1);
        }
        
        return ans;
    }
};