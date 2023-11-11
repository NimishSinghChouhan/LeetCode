class Solution {
public:
    int trailingZeroes(int n) {
        //matching count of 2 and 5
        int two_count = 0, five_count = 0;
        
        for(int i = 1; n >= pow(5,i); i++){
            five_count += n/pow(5,i);
        }
        
        for(int i = 1; n >= pow(2,i); i++){
            two_count += n/pow(2,i);
        }
        
        return min(two_count, five_count);
    }
};