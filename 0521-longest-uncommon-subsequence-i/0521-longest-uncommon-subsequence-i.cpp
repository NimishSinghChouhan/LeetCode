class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a != b){
            return max(a.size(), b.size());
        }
        return -1;
    }
};