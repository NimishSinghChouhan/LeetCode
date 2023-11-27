class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        
        //sort by start point
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(vector<int>& interval : intervals){
            if(ans.empty() || ans.back()[1] < interval[0]){
                ans.push_back(interval);
            }else{
                ans[ans.size()-1][1] = max(ans.back()[1], interval[1]);
            }
        }
        
        return ans;
    }
};