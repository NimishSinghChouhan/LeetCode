class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        
        for(char c : s){
            if(count.find(c) == count.end()){
                count[c] = 1;
            }else{
                count[c]++;
            }
        }
        
        int ans = 0, maxOdd = 0;
        for(map<char, int>::iterator it = count.begin(); it!= count.end(); it++){
            ans += it->second/2*2;
            if(ans%2 == 0 && it->second%2 == 1){
                ans++;
            }
        }
        return ans+maxOdd;
    }
};