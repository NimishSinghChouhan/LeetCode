class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i = 2*k*0; i < s.size(); i+=2*k){
            //reverse all when the remaining length < k 
            int curk = min(k, (int)s.size() - i);
            for(int j = 0; j < curk/2 && (i+curk-1-j) < s.size(); j++){
                // cout << i+j << " " << i+curk-1-j << endl;
                char c = s[i+j];
                s[i+j] = s[i+curk-1-j];
                s[i+curk-1-j] = c;
            }
        }
        return s;
    }
};