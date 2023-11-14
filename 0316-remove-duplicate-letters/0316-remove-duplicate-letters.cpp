class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> counter(26, 0);
        
        //the stack stores the char used to construct the answer
        stack<char> stk;
        //a look up table for the stack, used to check whether a char is added into the stack
        vector<bool> visited(26, false);
        
        int n = s.size();
        
        for(int i = 0; i < n; ++i){
            ++counter[s[i]-'a'];
        }
        
        for(char& c : s){
            --counter[c-'a'];
            
            //skip duplicate char
            if(visited[c-'a'])
                continue;
            
            /*
            current char is smaller,
            after ensuring that there are more "stk.top()" after current char,
            we can safely remove it from stack
            (the char "stk.top()" will later be added again)
            */
            
            /*
            for large char, after it is pushed into stack, 
            it will be popped again, 
            so it will be put as later as possible
            */
            while(!stk.empty() && c < stk.top() && counter[stk.top()-'a'] > 0){
                char topc = stk.top();
                stk.pop();
                visited[topc-'a'] = false;
            }
            
            /*
            for small char, after it is pushed into stack, 
            it won't be popped again, 
            so it can be put at former place in the final string
            */
            stk.push(c);
            visited[c-'a'] = true;
        }
        
        string ans;
        
        while(!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};