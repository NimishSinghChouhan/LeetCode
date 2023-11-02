class Solution {
public:
    int ans;
    int depth(TreeNode* node){
        if(node == NULL) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L+R);
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
};