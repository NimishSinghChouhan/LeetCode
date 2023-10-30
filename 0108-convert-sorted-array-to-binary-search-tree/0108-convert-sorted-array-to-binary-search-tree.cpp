class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int start, int end){
        //end + 1 - start : the length of subarray
        if(end + 1 - start < 1) return NULL;
        int mid = (start+end)/2;
        //https://stackoverflow.com/questions/5914422/proper-way-to-initialize-c-structs
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid-1);
        root->right = buildTree(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        TreeNode* root = buildTree(nums, 0, nums.size()-1);
        return root;
    }
};