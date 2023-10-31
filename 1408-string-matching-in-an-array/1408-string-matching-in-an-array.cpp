class Solution {
public:
    vector<int> build(string& pat){
        int n = pat.size();
        vector<int> lps(n, 0);
        
        for(int i = 1, len = 0; i < n; ){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else if(len > 0){
                //fallback to compare with a shorter prefix/suffix
                len = lps[len-1];
            }else{
                //len equals to 0 here
                lps[i] = 0;
                i++;
            }
        }
        
        return lps;
    };
    
    bool search(string& text, string& pat){
        int m = text.size(), n = pat.size();
        if(n == 0) return false;
        
        vector<int> lps = build(pat);
        
        for(int i = 0, j = 0; i < m; ){
            if(text[i] == pat[j]){
                i++;
                j++;
            }
            
            if(j == n){
                return true;
            }
            
            if(i < m && text[i] != pat[j]){
                if(j > 0){
                    //j now serves as len in bulid()
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        
        return false;
    };
    
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        
        //sort by length, ascending
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        
        for(int pi = 0; pi < words.size(); pi++){
            //examine pattern one by one
            for(int ti = pi+1; ti < words.size(); ti++){
                if(search(words[ti], words[pi])){
                    ans.push_back(words[pi]);
                    //if words[pi] is a substring of any longer words, break at once so that there won't be duplicate element in ans
                    break;
                }
            }
        }
        
        return ans;
    }
};