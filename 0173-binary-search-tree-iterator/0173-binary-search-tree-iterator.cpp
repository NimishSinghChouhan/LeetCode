class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* cur;
    
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top(); stk.pop();
        int val = cur->val;
        cur = cur->right;
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !stk.empty();
    }
};
 