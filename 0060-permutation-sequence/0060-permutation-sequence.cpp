class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        
        int fact = 1;
        for(int i = 1; i <= n; ++i){
            fact *= i;
        }
        
        --k; //1-based -> 0-based
        for(int i = 0; i < n; ++i){
            //there could be (n-1)! permutations if we exclude one char
            fact /= (n-i);
            //the kth permutation belongs to what group
            int groupid = k/fact;
            ans += (nums[groupid] + '0');
            nums.erase(nums.begin()+groupid);
            //there are "groupid" groups before the visited group
            k -= fact * groupid;
        }
        
        return ans;
    }
};