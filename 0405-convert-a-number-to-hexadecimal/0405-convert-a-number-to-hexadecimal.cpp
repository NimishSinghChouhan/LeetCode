class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        
        string ans;
        vector digits = {'0', '1', '2', '3', '4', '5', '6', '7',
                        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        
        unsigned int unum;
        
        if(num < 0) unum = UINT_MAX + 1 + (unsigned int)num;
        else unum = num;
        
        while(unum > 0){
            ans = digits[unum%16] + ans;
            unum/=16;
        }
        
        return ans;
    }
};