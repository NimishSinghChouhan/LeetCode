class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        TreeNode* cur;
        
        while(!stk.empty()){
            cur = stk.top(); stk.pop();
            
            ans.emplace_back(cur->val);
            if(cur->right) stk.push(cur->right);
            if(cur->left) stk.push(cur->left);
        }
        
        return ans;
    }
};