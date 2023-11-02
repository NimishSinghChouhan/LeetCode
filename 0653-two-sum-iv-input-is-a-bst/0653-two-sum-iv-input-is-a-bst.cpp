class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<int> v; //values seen
        TreeNode* cur;
        
        q.push(root);
        
        while(!q.empty()){
            cur = q.front();
            q.pop();
            
            for(int e : v){
                if(e+cur->val==k){
                    return true;
                }
            }
            v.push_back(cur->val);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        
        return false;
    }
};