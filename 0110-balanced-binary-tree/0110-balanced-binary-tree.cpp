class Solution {
public:
    int treeDepth(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(treeDepth(root->left), treeDepth(root->right));
    }
    // bool isSubtreeBalanced(TreeNode* root){
    //     if(root == NULL) return true;
    //     return abs(treeDepth(root->left) - treeDepth(root->right)) <= 1;
    // }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        // return isSubtreeBalanced(root) && isSubtreeBalanced(root->left) && isSubtreeBalanced(root->right);
        // cout << root->val << endl;
        // if(abs(treeDepth(root->left) - treeDepth(root->right)) > 1){
        //     cout << "***" << root->val << "***" << endl;
        //     cout << (root->left->val) << " " <<(root->right->val) << endl;
        //     cout << treeDepth(root->left) << " " << treeDepth(root->right) << endl;
        // }
        return (abs(treeDepth(root->left) - treeDepth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
};