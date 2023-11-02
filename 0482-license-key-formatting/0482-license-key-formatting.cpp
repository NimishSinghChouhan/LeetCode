class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";

        for (int i = S.size() - 1; i >= 0; i--){
            if (S[i] != '-'){
                //need a '-' so that ans.size() is multiple of (K+1)
                if(ans.size() % (K + 1) == K) ans += '-';
                ans += S[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        transform(ans.begin(), ans.end(), ans.begin(), [](unsigned char c){return toupper(c);});

        return ans;
    }
};