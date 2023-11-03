class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        if(n == 2) return true;
        
        //the vector from coordinates[0] to coordinates[1]
        vector<int> v1 = {coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]};
        vector<int> v2;
        
        for(int i = 2; i < n; i++){
            v2 = {coordinates[i][0] - coordinates[0][0], coordinates[i][1] - coordinates[0][1]};
            //cross product
            //this is equivalent to comparing their slope: v2[1]/v2[0] == v1[1]/v1[0]
            if(v1[0]*v2[1] - v1[1]*v2[0] != 0) return false;
        }
        
        return true;
    }
};