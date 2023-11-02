class Solution {
public:
    string tree2str(TreeNode* t) {
        string ans = "";
        
        if(!t) return ans;
        
        ans = to_string(t->val);
        if(t->left && t->right){
            ans += "(" + tree2str(t->left) + ")";
            ans += "(" + tree2str(t->right) + ")";
        }else if(t->left && !t->right){
            ans += "(" + tree2str(t->left) + ")";
        }else if(!t->left && t->right){
            ans += "()";
            ans += "(" + tree2str(t->right) + ")";
        }
        
        return ans;
    }
};