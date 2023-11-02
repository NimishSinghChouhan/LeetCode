class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<char, int>> v;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            auto it = find_if(v.begin(), v.end(), 
                [&c](const pair<char, int>& p){return p.first == c;});
            if(it == v.end()){
                //first meet
                v.push_back(make_pair(c, i));
            }else{
                it->second = -1;
            }
        }
        
        int ans = -1;
        
        for(pair<char,int>& p : v){
            if(p.second != -1){
                ans = p.second;
                break;
            }
        }
        
        return ans;
    }
};