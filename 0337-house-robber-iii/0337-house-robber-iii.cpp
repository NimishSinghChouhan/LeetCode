class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        if(memo.find(root) != memo.end()) return memo[root];
        
        int robHere = root->val;
        if(root->left) robHere += rob(root->left->left) + rob(root->left->right);
        if(root->right) robHere += rob(root->right->left) + rob(root->right->right);
        
        int robNext = rob(root->left) + rob(root->right);
        
        memo[root] = max(robHere, robNext);
        return memo[root];
    }
};
