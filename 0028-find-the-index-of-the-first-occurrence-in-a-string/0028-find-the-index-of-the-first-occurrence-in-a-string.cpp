class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        //i + max possible value of j should less than haystack.size()
        for(int i = 0; i + needle.size() - 1 < haystack.size(); i++){
            //break and use next i when we encounter mismatch
            for(int j = 0; j < needle.size() && haystack[i+j] == needle[j]; j++){
                //we can match to the end of needle
                if(j == needle.size()-1) return i;
            }
        }
        
        return -1;
    }
};
