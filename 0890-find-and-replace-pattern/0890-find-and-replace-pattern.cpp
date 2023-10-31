class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> remain_words;
        for(int i = 0; i < words.size(); i++){
            map<char, char> pt2word;
            map<char, char> word2pt;
            bool match = true;
            for(int j = 0; j < words[i].size(); j++){
                if(pt2word.find(pattern[j])==pt2word.end()){ //not in map
                    pt2word.insert(make_pair(pattern[j], words[i][j]));
                }
                if(word2pt.find(words[i][j])==word2pt.end()){ //not in map
                    word2pt.insert(make_pair(words[i][j], pattern[j]));
                }
                if((words[i][j] != pt2word[pattern[j]]) || (pattern[j] != word2pt[words[i][j]])){
                    match = false;
                    break;
                }
            }
            if(match){
                remain_words.push_back(words[i]);
            }
        }
        return remain_words;
    }
};