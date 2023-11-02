class Solution {
public:
    vector<int> ans;
    int prev = INT_MIN;
    int curcount = 1; //since we only update curcount when it's not first node
    int maxcount = 0;
    
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        //we only update curcount when it's not first node
        if(prev != INT_MIN){
            if(root->val == prev){
                curcount++;
            }else{
                curcount = 1;
            }
        }
        prev = root->val;
        if(curcount > maxcount){
            maxcount = curcount;
            ans.clear();
            // cout << "if: " << curcount << " " << maxcount << " " << root->val << endl;
            ans.push_back(root->val);
        }else if(curcount == maxcount){
            // cout << "else: " << curcount << " " << maxcount << " " << root->val << endl;
            ans.push_back(root->val);
        }
        traverse(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        if(!root) return vector<int>();
        traverse(root);
        cout << endl;
        return ans;
    }
};