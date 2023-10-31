class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cur1 = 0, cur2 = 0;
        int ans = 0;
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        while(cur1 < g.size() && cur2 < s.size()){
            if(s[cur2] >= g[cur1]){
                ans++;
                cur1++;
                cur2++;
            }else{
                cur2++;
            }
        }
        
        return ans;
    }
};