class Solution {
public:
    string toGoatLatinToken(string token, int order, string delimeter){
        if(!(token[0]=='a' || token[0]=='e' || token[0]=='i' || token[0]=='o' || token[0]=='u' || token[0]=='A' || token[0]=='E' || token[0]=='I' || token[0]=='O' || token[0]=='U')){
            token += token[0];
            token.erase(token.begin());
        }
        string aMul(order, 'a');
        return token + "ma" + aMul + delimeter;
    }
    
    string toGoatLatin(string S) {
        string ans;
        size_t pos = 0;
        string token;
        int order = 1;
        string delimeter = " ";
        while ((pos = S.find(delimeter)) != string::npos) {
            token = S.substr(0, pos);
            ans += toGoatLatinToken(token, order, delimeter);
            order++;
            S.erase(0, pos + delimeter.size());
        }
        ans += toGoatLatinToken(S, order, "");
        return ans;
    }
};