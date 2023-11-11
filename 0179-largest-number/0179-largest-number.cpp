class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(), nums.end());
        if(max_ele == 0) return "0";
        
        sort(nums.rbegin(), nums.rend(), 
             [](int& a, int& b){
                 return to_string(a)+to_string(b) < to_string(b)+to_string(a);});
        
        string ans;
        for(int& num : nums){
            ans += to_string(num);
		}
        return ans;
    }
};