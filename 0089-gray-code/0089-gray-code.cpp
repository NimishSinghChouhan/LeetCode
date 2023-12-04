class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        
        for(int i = 0; i < n; ++i){
            /*
            in ith iteration, 
            we change res of size 1<<i to
            res of size 1<<(i+1)
            
            in ith iteration,
            the range of res is [0,1<<(i+1)),
            we already have range [0,1<<i),
            now we need to add range[1<<i,1<<(i+1)),
            and we can create it by 
            adding 1<<i to the old range
            */
            int prependVal = 1 << i;
            int oldSize = res.size();
            //double the size of res
            for(int j = oldSize-1; j >= 0; --j){
                res.push_back(prependVal + res[j]);
            }
            /*
            the numbers in the later half all diff by one bit,
            because they are created from the old res
            
            res[oldSize-1] and res[oldSize] diff by one bit
            (the most significant bit)
            
            res[newSize-1] and res[0] diff by one bit
            (the most significant bit)
            */
        }
        
        return res;
    }
};