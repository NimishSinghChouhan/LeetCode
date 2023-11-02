class Solution {
public:
    int maxDepth(Node* root) {
        stack<pair<Node*, int> > stk;
        int depth = 0;
        
        if(root!=NULL)
            stk.push(make_pair(root, 1));
        
        while(!stk.empty()){
            pair<Node*, int> p = stk.top();
            stk.pop();
            
            Node* node = p.first;
            int currentDepth = p.second;
            depth = max(depth, currentDepth);
            
            for(Node* child : node->children){
                stk.push(make_pair(child, currentDepth+1));
            }
            
        }
        
        return depth;
    }
};
