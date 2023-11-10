class TrieNode{
public:
    vector<TrieNode*> children;
    int index;
    vector<int> palins;
    
    TrieNode(){
        children = vector<TrieNode*>(26);
        index = -1;
    }
};

class Trie{
private:
    TrieNode* root;
    
    bool isPalindrome(string& str, int l, int r){
        // cout << "check ";
        // for(int i = l; i <= r; ++i){
        //     cout << str[i];
        // }
        // cout << endl;
        for(; l < r; ++l, --r){
            if(str[l] != str[r]){
                return false;
            }
        }
        
        return true;
    };
public:
    Trie(){
        root = new TrieNode();
    }
    
    void add(string& word, int index){
        TrieNode* cur = root;
        
        /*
        insert into trie in reverse order,
        then in "find", 
        we can search each char in positive order
        */
        for(int i = word.size()-1; i >= 0; --i){
            /*
            note: "cur" in now on the word[i+1]!
            so we only have seen [i+1,n-1]!
            */
            // cout << "we are at " << word.substr(i+1) << endl;
            if(isPalindrome(word, 0, i)){
                /*
                palins serves as a summary of a node's descendants
                */
                /*
                we have seen word[i, n-1],
                remaining word[0, i-1] needed to be check
                */
                cur->palins.push_back(index);
            }
            char c = word[i];
            if(cur->children[c-'a'] == nullptr){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->index = index;
        //empty string is also a palindrome?
        cur->palins.push_back(index);
    }
    
    void find(string& word, int index, vector<vector<int>>& res){
        TrieNode* cur = root;
        
        for(int i = 0; i < word.size(); ++i){
            /*
            note: "cur" in now on the word[i-1]!
            so we only have seen [0,i-1]!
            */
            // cout << "we are at " << word.substr(0, i) << endl;
            if(cur->index != -1 && cur->index != index && isPalindrome(word, i, word.size()-1)){
                //cur->index != -1: current node serves as a leaf
                //cur->index != index: avoid finding itself!
                //isPalindrome(word, i+1, word.size()-1): word[i+1,n-1] is a palindrome
                res.push_back({index, cur->index});
            }
            
            char c = word[i];
            
            if(cur->children[c-'a'] == nullptr) return;
            
            cur = cur->children[c-'a'];
        }
        //now we have finished the "word" to be searched
        
        //but we haven't go to the leaf
        for(int palinIndex : cur->palins){
            if(palinIndex == index) continue;
            res.push_back({index, palinIndex});
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        int n = words.size();
        
        for(int i = 0; i < n; ++i){
            // cout << "===add " << words[i] << "===" << endl;
            trie->add(words[i], i);
        }
        
        vector<vector<int>> res;
        
        for(int i = 0; i < n; ++i){
            // cout << "===find " << words[i] << "===" << endl;
            trie->find(words[i], i, res);
        }
        
        return res;
    }
};