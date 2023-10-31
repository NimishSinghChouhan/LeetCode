class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        vector<int> key;
        
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int n : nums){
            if(count.find(n) == count.end()){
                count[n] = 1;
                key.push_back(n);
            }else{
                count[n]++;
            }
        }
        
        for(int i = 1; i < key.size(); i++){
            int k1 = key[i], k2 = key[i-1];
            if(k1 - k2 == 1) ans = max(ans, count[k1] + count[k2]);
            // cout << k1 << ", " << k2 << ", " << count[k1] << ", " << count[k2] << endl;
        }
        
        return ans;
    }
};