class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        vector<int> levelVals;
        int level = 0, levelCount = 1, nextLevelCount = 0;
        
        q.push(root);
        
        while(q.size()!=0){
            TreeNode* cur = q.front();
            q.pop();
            
            levelVals.push_back(cur->val);
            
            levelCount--;
            
            if(cur->left!=NULL){
                q.push(cur->left);
                nextLevelCount++;
            }
            
            if(cur->right!=NULL){
                q.push(cur->right);
                nextLevelCount++;
            }
            
            if(levelCount==0){
                levelCount = nextLevelCount;
                nextLevelCount = 0;
                level++;
                double levelSum = accumulate(levelVals.begin(), levelVals.end(), 0.0);
                ans.push_back(levelSum/levelVals.size());
                levelVals.clear();
            }
        }
        
        return ans;
    }
};