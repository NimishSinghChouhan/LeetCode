class TrieNode{
public:
    bool isEnd;
    vector<TrieNode*> children;
    char c;
    
    TrieNode(char c = '\0'){
        isEnd = false;
        this->c = c;
        children = vector<TrieNode*>(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(node->children[c-'a'] == nullptr){
                node->children[c-'a'] = new TrieNode(c);
            }
            node = node->children[c-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word){
            if(node->children[c-'a'] == nullptr) return false;
            node = node->children[c-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c : prefix){
            if(node->children[c-'a'] == nullptr) return false;
            node = node->children[c-'a'];
        }
        return true;
    }
};