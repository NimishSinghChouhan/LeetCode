class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        //in-order traversal
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* newcur = NULL;
        TreeNode* newroot = NULL;
        bool isFirst = true;
        
        while(cur!=NULL || stk.size() > 0){
            while(cur!=NULL){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            
            TreeNode node = TreeNode(cur->val);
            if(isFirst){
                newroot = new TreeNode(cur->val);
                newcur = newroot;
                isFirst = !isFirst;
            }else{
                newcur->right = new TreeNode(cur->val);
                newcur = newcur->right;
            }
            
            cur = cur->right;
        }
        
        return newroot;
    }
};