class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        //padding to the bottom and to the right
        vector<vector<int>> minhp(m+1, vector<int>(n+1, INT_MAX));
        
        /*
        (m,n-1) and (m-1, n) is the bottom neighbor and 
        right neighbor of princess
        */
        minhp[m][n-1] = minhp[m-1][n] = 1;
        
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                minhp[i][j] = max(
                    min(minhp[i+1][j], minhp[i][j+1]) - dungeon[i][j], 
                    1);
            }
        }
        
        return minhp[0][0];
    }
};