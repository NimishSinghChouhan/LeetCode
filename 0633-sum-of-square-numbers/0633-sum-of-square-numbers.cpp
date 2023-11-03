class Solution {
public:
    bool judgeSquareSum(int c) {
        //check for factor in the range [2, sqrt(c)]
        for(int p = 2; p*p <= c; p++){
            //p : candidate prime factor of c
            int count = 0;
            if(c % p == 0){ //p is a prime factor of c 
                //every time we find a prime factor,
                // we divide c by p so that c won't have p as factor anymore
                //the maximum time a factor can occur is log(c)
                while(c % p == 0){
                    count++;
                    c /= p;
                }
                if(p % 4 == 3 && count % 2 != 0){
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};