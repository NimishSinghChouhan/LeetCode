class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t){
        //this version not allow search t in s's subtree,
        //it just compare whether s equals to t
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        //both not empty
        //s and t are same tree
        if((s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right)) return true;
        //if s and t are not the same,
        //keep find t in s's subtree
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};