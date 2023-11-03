class Solution {
public:
    int balancedStringSplit(string s) {
        int rcount = 0, lcount = 0;
        int sbcount = 0;
        for(char c : s){
            if(c == 'R'){
                rcount++;
            }else{
                lcount++;
            }
            if(rcount == lcount){
                sbcount++;
            }
        }
        return sbcount;
    }
};