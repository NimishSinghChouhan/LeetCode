class Solution {
public:
    map<int, int> depth;
    map<int, TreeNode*> parent;
    
    void dfs(TreeNode* node, TreeNode* par){
        if(node!=NULL){
            cout << node-> val;
            depth[node->val] = par!=NULL?1+depth[par->val]:0;
            //can't use parent.insert(node->val, par)!
            parent[node->val] = par;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL);
        return (depth[x] == depth[y] && parent[x] != parent[y]);
    }
};