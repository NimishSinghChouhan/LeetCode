class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string prev = countAndSay(n-1);
        
        char c = prev[0];
        int count = 1;
        string cur;
        
        for(int i = 1; i < prev.size(); i++){
            if(prev[i] == c){
                count++;
            }else{
                cur += to_string(count) + c;
                c = prev[i];
                count = 1;
            }
        }
        
        cur += to_string(count) + c;
        return cur;
    }
};