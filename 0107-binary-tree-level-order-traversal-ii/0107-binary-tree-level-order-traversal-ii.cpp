/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root != nullptr){
            TreeNode* cur;
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){
                int levelSize = q.size();
                vector<int> level;
                while(levelSize-- > 0){
                    cur = q.front(); q.pop();

                    level.push_back(cur->val);

                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
                ans.insert(ans.begin(), level);
            }
        }
        
        return ans;
    }
};