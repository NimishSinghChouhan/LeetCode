class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            swap(cur->left, cur->right);
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
        }
        return root;
    }
};