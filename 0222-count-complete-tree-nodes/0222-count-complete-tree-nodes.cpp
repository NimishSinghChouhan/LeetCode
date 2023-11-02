class Solution {
public:
    int height(TreeNode* node){
        return (node == nullptr) ? -1 : 1 + height(node->left);
    };
    
    int countNodes(TreeNode* root) {
        int count = 0, h = height(root);
        
        while(root != nullptr){
            if(height(root->right) == h-1){
                //add left subtree and root's count
                count += (1<<h);
                root = root->right;
            }else{
                //add right subtree and root's count
                count += (1<<h-1);
                root = root->left;
            }
            /*
            in next iteration,
            we look into the incomplete left or right subtree,
            and it's height is current height -1
            */
            --h;
        }
        
        return count;
    }
};