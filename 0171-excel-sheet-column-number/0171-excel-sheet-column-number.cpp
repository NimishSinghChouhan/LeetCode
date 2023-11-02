class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(string::reverse_iterator r = s.rbegin(); r!=s.rend(); r++){
            ans += (*r - 'A' + 1) * pow(26, (r - s.rbegin()));
        }
        return ans;
    }
};