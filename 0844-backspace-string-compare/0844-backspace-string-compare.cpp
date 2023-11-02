class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stkS, stkT;
        
        for(char c : S){
            if(c == '#' && !stkS.empty()) stkS.pop();
            else if(c != '#') stkS.push(c);
            //ignore '#' when stack is empty
        }
        
        for(char c : T){
            if(c == '#' && !stkT.empty()) stkT.pop();
            else if(c != '#') stkT.push(c);
        }
        
        if(stkS.size() != stkT.size()) return false;
        
        while(!stkS.empty() && !stkT.empty()){
            char cS = stkS.top(), cT = stkT.top();
            if(cS != cT) return false;
            stkS.pop();
            stkT.pop();
        }
        
        if(!stkS.empty() || !stkT.empty()) return false;
        return true;
    }
};
