class Solution {
public:
    bool isValid(string s) {
        map<char, char> paren;
        paren['('] = ')';
        paren['{'] = '}';
        paren['['] = ']';
        
        set<char> keys = {'(', '{', '['};
        
        stack<char> stk;
        
        for(char c : s){
            if(keys.find(c) != keys.end()){//left
                stk.push(c);
            }else if(!stk.empty() && paren[stk.top()] == c){//right, match
                stk.pop();
            }else{//right, not match
                return false;
            }
        }
        
        return stk.empty();
    }
};