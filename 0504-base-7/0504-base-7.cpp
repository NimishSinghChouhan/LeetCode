class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        
        bool neg = (num < 0);
        int digit = 0;
        int ans = 0;
        
        if(neg) num*=(-1);
        
        while(num > 0){
            // cout << (num%7) * pow(10, digit) << " ";
            ans += (num%7) * pow(10, digit);
            num/=7;
            digit++;
        }
        // cout << endl;
        
        if(neg) return "-" + to_string(ans);
        return to_string(ans);
    }
};