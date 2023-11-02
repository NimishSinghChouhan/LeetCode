class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int unival = root->val;
        TreeNode* cur = root;
        queue<TreeNode*> queue;
        queue.push(cur);
        
        while(!queue.empty()){
            if(cur->val!=unival){
                return false;
            }
            if(cur->left!=NULL)
                queue.push(cur->left);
            if(cur->right!=NULL)
                queue.push(cur->right);
            cur = queue.front();
            queue.pop();
        }
        
        return true;
    }
};