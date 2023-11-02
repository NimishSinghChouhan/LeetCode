class Solution {
public:
    int treeSum(TreeNode* root){
        if(!root) return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }
    
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        return abs(treeSum(root->left) - treeSum(root->right)) + \
            findTilt(root->left) + findTilt(root->right);
    }
};