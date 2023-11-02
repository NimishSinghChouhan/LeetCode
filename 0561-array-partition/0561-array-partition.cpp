class Solution {
public:
    static int compare (const void * a, const void * b)
    {
      return ( *(int*)a - *(int*)b );
    }
    
    int arrayPairSum(vector<int>& nums) {
        int ans = 0;
        // sort(nums.begin(), nums.end());
        
        //https://stackoverflow.com/questions/12308243/trying-to-use-qsort-with-vector
        qsort(&nums[0], nums.size(), sizeof(int), compare);
        
        for(int i = 0; i < nums.size(); i++){
            if(i%2==0) ans+=nums[i];
        }
        return ans;
    }
};