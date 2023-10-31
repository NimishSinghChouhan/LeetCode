class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool isIncreasing = true, isDecreasing = true;
        //length 1 or 2 A is default to monotonic
        for(int i = 0; i < A.size()-1; i++){
            if(A[i+1]-A[i]<0){
                isIncreasing = false;
            }
            if(A[i+1]-A[i]>0){
                isDecreasing = false;
            }
            if(!isIncreasing && !isDecreasing){
                return false;
            }
        }
        return isIncreasing || isDecreasing;
    }
};