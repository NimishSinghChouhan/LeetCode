/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *p, *q, *ans;
    
    bool recurseTree(TreeNode* cur){
        if(cur == nullptr) return false;
        
        int mid = (int)(cur == p || cur == q);
        int left = (int)recurseTree(cur->left);
        int right = (int)recurseTree(cur->right);
        
        /*
        mid & left : current node is lca
        mid & right: current node is lca
        left& right: their parent, which is current node, is lca
        */
        if(mid + left + right >= 2){
            ans = cur;
        }
        
        //if itself or one of its children is p or q's ancestor
        return mid + left + right > 0;
    };
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        recurseTree(root);
        return ans;
    }
};