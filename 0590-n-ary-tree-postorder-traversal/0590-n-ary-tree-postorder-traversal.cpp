class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        stack<Node*> stk;
        
        stk.push(root);
        
        while(!stk.empty()){
            Node* node = stk.top();
            stk.pop();
            
            if(node==NULL)continue;
            
            for(Node* child : node->children){
                stk.push(child);
            }
            
            ans.insert(ans.begin(), node->val);
        }
        return ans;
    }
};

