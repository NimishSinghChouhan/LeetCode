class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return vector<string>();
        //leaf node
        if(!root->left && !root->right)
            return vector<string> {to_string(root->val)};
        vector<string> ans;
        if(root->left){
            for(string s : binaryTreePaths(root->left)){
                ans.push_back(to_string(root->val)+"->"+s);
                // cout << to_string(root->val)+"->"+s << endl;
            }
        }
        if(root->right){
            for(string s : binaryTreePaths(root->right)){
                ans.push_back(to_string(root->val)+"->"+s);
                // cout << to_string(root->val)+"->"+s << endl;
            }
        }
        return ans;
    }
};