class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int evenix = 0;
        int oddix = 1;
        
        for(int evenix = 0; evenix < A.size(); evenix+=2){
            if(A[evenix]%2==1){
                while(A[oddix]%2==1)
                    oddix+=2;
                int tmp = A[evenix];
                A[evenix] = A[oddix];
                A[oddix] = tmp;
            }
        }
        return A;
    }
};