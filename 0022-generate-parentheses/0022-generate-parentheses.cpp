class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return {""};
        vector<string> ans;
        for(int c = 0; c < n; c++){
            for(string left : generateParenthesis(c)){
                for(string right : generateParenthesis(n-1-c)){
                    ans.push_back("(" + left + ")" + right);
                }
            }
        }
        
        return ans;
    }
};