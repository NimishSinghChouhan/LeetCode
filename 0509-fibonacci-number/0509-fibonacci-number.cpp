class Solution {
public:
    int fib(int N) {
        if(N==0 or N==1){
            return N;
        }
        vector<int> arr = {0, 1};
        while(arr.size() < N+1){
            arr.push_back(arr[arr.size()-1] + arr[arr.size()-2]);
        }
        return arr[arr.size()-1];
    }
};