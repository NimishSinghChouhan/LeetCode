class Solution {
public:
    int findComplement(int num) {
        /*
        suppose num is 5, which is 0....0101,
        we know that the first '1' of binary representation of 5 appears at 2nd digit
        we want to generate a mask s.t. 
        0...0111, (31-3rd digit is 0, and 2nd,1st,0th digit is 1)
        and then just do xor to get the complement
        */
        //1...1(32 bits)
        unsigned int mask = ~0;
        //we want mask and num's intersection be 0
        while(mask & num){
            mask <<= 1;
        }
        //now we use ~mask
        return ~mask ^ num;
    }
};