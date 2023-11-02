class Solution {
public:
    int countSetBits(int n){
        int counts = 0;
        while(n!=0){
            counts+=(n%2);
            n/=2;
        }
        // cout << counts << " ";
        return counts;
    }
    
    bool checkIsPrime(int n){
        if(n==1) return false;
        int sqr = floor(sqrt(n));
        while(sqr>1){
            //check whether n is divisible by 2,3,5,...
            if(n%sqr==0){
                return false;
            }
            sqr--;
        }
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int n = L; n <= R; n++){
            if(checkIsPrime(countSetBits(n))){
                ans++;
            }
        }
        // cout << endl;
        return ans;
    }
};