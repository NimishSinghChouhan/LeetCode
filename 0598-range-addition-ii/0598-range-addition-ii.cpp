class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rsize = m, csize = n;
        
        for(vector<int>& op : ops){
            rsize = min(rsize, op[0]);
            csize = min(csize, op[1]);
        }
        
        return rsize * csize;
    }
};