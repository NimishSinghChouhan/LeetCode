class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //i: consider arr[1...i], index is 1-based
        int l = 0, r = arr.size();
        int m;
        
        while(l < r){
            m = (l+r+1) >> 1;
            // cout << l << ", " << m << ", " << r << endl;
            // if(m > 0) cout << "m: " << arr[m-1] - m << endl;
            
            /*
            arr[1...m] - m: 
            in the range arr[1...m](index is 1-based),
            there are m numbers not missing,
            so the number of missing numbers is arr[m] - m
            */
            if(m == 0 || arr[m-1] - m < k){
                l = m;
            }else{
                r = m-1;
            }
        }
        
        return l + k;
    }
};