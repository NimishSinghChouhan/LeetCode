class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        
        int n = A.size();
        
        int diff_count = 0;
        unordered_map<int, int> counter;
        vector<int> diffs;
        bool dup = false;
        
        for(int i = 0; i < n; ++i){
            if(A[i] != B[i]) diffs.push_back(i);
            ++counter[A[i]];
            if(counter[A[i]] >= 2) dup = true;
        }
        
        if(diffs.empty() && dup) return true;
        
        if(diffs.size() != 2) return false;
        
        /*
        for diffs.size() == 2,
        still need to check if swap works:
        e.g. swap not works for the case:
        "abcaa"
        "abcbb"
        */
        swap(A[diffs[0]], A[diffs[1]]);
        
        return A == B;
    }
};