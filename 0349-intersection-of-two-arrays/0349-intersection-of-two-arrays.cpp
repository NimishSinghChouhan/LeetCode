class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> ans(max(nums1.size(), nums2.size()));
        vector<int>::iterator it = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), ans.begin());
        ans.resize(it - ans.begin());
        return ans;
    }
};