class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> leftLower(n);
        vector<int> rightLower(n);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int p = i-1;
            /*
            if i-1's height >= i's height,
            we need to go backward.
            since heights[p] >= heights[i] and
            all q in [leftLower[p]+1, p-1] >= heights[p],
            so we skip these q and choose leftLower[p] as our next trial
            */
            while(p >= 0 && heights[p] >= heights[i]){
                p = leftLower[p];
            }
            leftLower[i] = p;
        }
        
        for(int i = n-1; i >= 0; i--){
            int p = i+1;
            
            while(p < n && heights[p] >= heights[i]){
                p = rightLower[p];
            }
            rightLower[i] = p;
        }
        
        for(int i = 0; i < n; i++){
            ans = max(ans, (rightLower[i]-leftLower[i]-1) * heights[i]);
        }
        
        return ans;
    }
};