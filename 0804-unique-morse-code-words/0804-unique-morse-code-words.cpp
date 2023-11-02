class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> uniqueMorses;
        for(int i = 0; i < words.size(); i++){
            string s;
            for(int j = 0; j < words[i].size(); j++){
                s+=morse[(int)(words[i][j]-'a')];
            }
            uniqueMorses.insert(s);
        }
        return uniqueMorses.size();
    }
};