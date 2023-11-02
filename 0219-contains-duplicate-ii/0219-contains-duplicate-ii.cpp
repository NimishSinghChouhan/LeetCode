class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> myset;
        for(int i = 0; i < nums.size(); i++){
            //window : [i-k, i]
            //so (i-k-1)th goes out of the window, need to remove it
            if(i-k-1 >= 0) myset.erase(nums[i-k-1]);
            /*
            The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the equivalent element already in the set. The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent element already existed.
            */
            if(!myset.insert(nums[i]).second) return true;
        }
        return false;
    }
};