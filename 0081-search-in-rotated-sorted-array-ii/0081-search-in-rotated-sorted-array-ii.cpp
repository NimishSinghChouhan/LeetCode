class Solution {
public:
    bool isBinarySearchHelpful(vector<int>& nums, int l, int ele){
        //if ele < nums[l], then ele is in second part
        //if ele > nums[l], then ele is in first part
        //if ele == nums[l], then it could exist in both parts
        // we should use the dynamically changed "l" rather than 0!!
        // l = 0;
        return nums[l] != ele;
    }
    
    bool isInFirst(vector<int>& nums, int l, int ele){
        // we should use the dynamically changed "l" rather than 0!!
        // l = 0;
        return ele >= nums[l];
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            // cout << l << ", " << mid << ", " << r << endl;
            
            int pivot = nums[mid];
            
            if(pivot == target){
                return true;
            }
            
            if(!isBinarySearchHelpful(nums, l, pivot)){
                ++l;
                continue;
            }
            
            bool pivotIsInFirst = isInFirst(nums, l, pivot);
            bool targetIsInFirst = isInFirst(nums, l, target);
            
            if(pivotIsInFirst ^ targetIsInFirst){
                //nums[mid] and target are in different array
                if(pivotIsInFirst){
                    //pivot in first, target in second, so search in right part
                    // cout << "p1t2" << endl;
                    l = mid+1;
                }else{
                    // cout << "p2t1" << endl;
                    r = mid-1;
                }
            }else{
                if(target > pivot){
                    // cout << "pt same, t > p" << endl;
                    l = mid+1;
                }else{
                    // cout << "pt same, t < p" << endl;
                    r = mid-1;
                }
            }
        }
        
        return false;
    }
};