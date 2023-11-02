class Solution {
public:
    int last = INT_MIN/2;
    int ans = INT_MAX;
    
    void inOrder(TreeNode* node){
        if(node->left) inOrder(node->left);
        ans = min(ans, node->val - last);
        last = node->val;
        if(node->right) inOrder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};