class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int start = 0, end = 0;
        char c = '\0';
        vector<vector<int>> ans;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] != c){
                //last group
                if(end - start >= 2){
                    //length > 3 group
                    ans.push_back(vector<int> {start, end});
                }
                //update for current group
                c = S[i];
                start = i;
                end = i;
            }else{
                end = i;
            }
            // cout << c << " " << start << " " << end << endl;
        }
        
        if(end - start >= 2){
            //length > 3 group
            ans.push_back(vector<int> {start, end});
        }
        
        return ans;
    }
};