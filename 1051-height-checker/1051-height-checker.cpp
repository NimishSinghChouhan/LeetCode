class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted_heights = heights;
        int num = 0;
        
        sort(sorted_heights.begin(), sorted_heights.end());
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != sorted_heights[i]) num++;
        }
        
        return num;
    }
};