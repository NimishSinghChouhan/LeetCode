class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0) return false;
        string ss = s + s;
        return ss.substr(1, ss.size()-2).find(s)!=string::npos;
    }
};