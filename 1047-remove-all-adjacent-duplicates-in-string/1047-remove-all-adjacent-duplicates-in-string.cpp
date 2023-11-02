class Solution {
public:
    string removeDuplicates(string S) {
        string ans = "";
        for(char c : S){
            if(ans.size() > 0 && c == ans.back()){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};