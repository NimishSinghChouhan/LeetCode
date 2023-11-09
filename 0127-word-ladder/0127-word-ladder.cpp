class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), beginWord);
        int start;
        if(it == wordList.end()){
            wordList.push_back(beginWord);
            start = wordList.size()-1;
        }else{
            start = it - wordList.begin();
        }
        
        it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;
        int end = it - wordList.begin();
        
        int m = beginWord.size();
        int n = wordList.size();
        //(generic word, id in wordList)
        unordered_map<string, vector<int>> allComboDict;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                //replace ith char with '*'
                string newword = wordList[i].substr(0, j) + '*' + wordList[i].substr(j+1);
                allComboDict[newword].push_back(i);
            }
        }
        
        //BFS
        queue<int> q;
        int cur;
        int level = 1; //the length of the path containing only start
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()){
            int levelSize = q.size();
            // cout << "level: " << level << ", levelSize: " << levelSize << endl;
            
            while(levelSize-- > 0){
                cur = q.front(); q.pop();
                // cout << wordList[cur] << endl;
            
                if(cur == end){
                    return level;
                }
                
                //iterate all char and build its generic word
                for(int i = 0; i < m; ++i){
                    string newword = wordList[cur].substr(0, i) + '*' + wordList[cur].substr(i+1);
                    
                    //use this generic word to find its neighbor
                    for(int nei : allComboDict[newword]){
                        if(!visited[nei]){
                            visited[nei] = true;
                            q.push(nei);
                        }
                    }
                }
            }
            
            ++level;
        }
        
        //cannot find a path
        return 0;
    }
};