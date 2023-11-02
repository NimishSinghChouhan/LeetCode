class Solution {
public:
    string reverseOnlyLetters(string S) {
        string ans(S.size(),  'a');
        
        //fill with non-alpha characters
        for(int i = 0; i < S.size(); i++){
            if(!isalpha(S[i])){
                ans[i] = S[i];
            }
        }
        
        int j = S.size()-1;
        for(int i = 0; i < S.size(); i++){
            if(!isalpha(S[i])){
                continue;
            }
            //the vector is initialized with 'a'!
            //use while rather than if!
            //skip all filled position
            while(!isalpha(ans[j])){
                j--;
            }
            ans[j--] = S[i];
        }
        
        return ans;
    }
};