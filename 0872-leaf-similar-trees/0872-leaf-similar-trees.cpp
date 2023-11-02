class Solution {
public:
    void build_leaf_values(TreeNode* root, vector<int>* leaf_values){
        stack<TreeNode*> stk;
        TreeNode* cur;
        
        stk.push(root);
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            
            if(cur->left==NULL && cur->right==NULL){
                leaf_values->push_back(cur->val);
            }else{
                if(cur->right) stk.push(cur->right);
                if(cur->left) stk.push(cur->left);
            }
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_values1, leaf_values2;
        
        build_leaf_values(root1, &leaf_values1);
        build_leaf_values(root2, &leaf_values2);
        
        if(leaf_values1==leaf_values2){
            return true;
        }else{
            return false;
        }
    }
};