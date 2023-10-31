class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        
        for(const string& log : logs){
            if(log == "./"){
                
            }else if(log == "../"){
                if(!stk.empty()) stk.pop();
            }else{
                stk.push(log);
            }
        }
        
        return stk.size();
    }
};