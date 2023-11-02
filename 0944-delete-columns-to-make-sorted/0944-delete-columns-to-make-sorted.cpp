class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int D=0;
        vector<string> B;
        //iterate A by column
        for(int j = 0; j < A[0].size(); j++){
            bool nonDecreasing = true;
            for(int i = 0; i < A.size()-1; i++){
                if(A[i+1][j]<A[i][j]){ //latter char should be greater or equal to current char
                    nonDecreasing = false;
                }
            }
            if(!nonDecreasing) D+=1;
        }
        return D;
    }
};