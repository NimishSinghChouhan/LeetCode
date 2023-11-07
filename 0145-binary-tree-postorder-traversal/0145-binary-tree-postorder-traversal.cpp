class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<TreeNode*> stk;
        stack<int> stk_val;
        
        stk.push(root);
        TreeNode* cur;
        
        while(!stk.empty()){
            cur = stk.top(); stk.pop();
            ans.insert(ans.begin(), cur->val);
            
            if(cur->left) stk.push(cur->left);
            if(cur->right) stk.push(cur->right);
        }
        
        return ans;
    }
};