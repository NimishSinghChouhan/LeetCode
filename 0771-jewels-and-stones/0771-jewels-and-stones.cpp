class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        for(char s : S){
            if(J.find(string(1, s)) != string::npos){
                ans++;
            }
        }
        return ans;
    }
};