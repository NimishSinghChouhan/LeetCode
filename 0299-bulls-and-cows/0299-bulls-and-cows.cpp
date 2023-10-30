class Solution {
public:
    string getHint(string secret, string guess) {
        int N = secret.size();
        int A = 0, B = 0;

        for(int i = N-1; i >= 0; i--){
            if(secret[i] == guess[i]){
                A++;
                secret.erase(i,1);
                guess.erase(i,1);
            }
        }
        
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
        int i = 0, j = 0;
        while(i < secret.size() && j < secret.size()){
            if(secret[i] == guess[j]){
                B++;
                i++;
                j++;
            }else if(secret[i] < guess[j]){
                i++;
            }else{
                j++;
            }
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};