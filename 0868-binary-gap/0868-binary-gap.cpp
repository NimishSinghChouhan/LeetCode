class Solution {
public:
    int binaryGap(int N) {
        vector<int> onePos;
        int digit = 0;
        int ans = 0;
        
        while(N!=0){
            if(N%2==1){
                onePos.push_back(digit);
            }
            N >>= 1; 
            digit++;
        }
        
        if(onePos.size()<2){
            return 0;
        }
        
        for(int i = 1; i < onePos.size(); i++){
            ans = max(onePos[i] - onePos[i-1], ans);
        }
        
        return ans;
    }
};