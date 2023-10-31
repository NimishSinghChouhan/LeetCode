class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds.front(), end = rounds.back();
        vector<int> ans;
        
        if(start <= end){
            ans = vector<int>(end-start+1);
            iota(ans.begin(), ans.end(), start);
            return ans;
        }
        
        //start > end
        //divide it to [start, n] and [1, end]
        
        //Method 1: slower
        // for(int i = 1; i <= end; ++i){
        //     ans.push_back(i);
        // }
        // for(int i = start; i <= n; ++i){
        //     ans.push_back(i);
        // }
        
        //Method 2: faster
        ans = vector<int>(end + n-start+1);
        iota(ans.begin(), ans.begin()+end, 1);
        iota(ans.begin()+end, ans.end(), start);
        
        return ans;
    }
};