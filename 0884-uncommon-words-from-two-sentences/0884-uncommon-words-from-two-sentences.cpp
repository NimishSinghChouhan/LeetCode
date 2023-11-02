class Solution {
public:
    vector<string> string_split(string str){
        size_t pos = 0;
        string token;
        string delimiter = " ";
        vector<string> str_vec;
        
        while ((pos = str.find(delimiter)) != string::npos) {
            token = str.substr(0, pos);
            str_vec.push_back(token);
            str.erase(0, pos + delimiter.length());
        }
        
        //add the last token
        str_vec.push_back(str);
        
        return str_vec;
    }
    
    template <class K, class V>
    void insert_or_increment(map<K,V>& mymap, K key, V inc){
        if(mymap.find(key)==mymap.end()){
            mymap[key] = 0+inc;
        }else{
            mymap[key] += inc;
        }
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> vA = string_split(A);
        vector<string> vB = string_split(B);
        map<string, int> mymap;
        vector<string> ans;
        
        for(string e : vA){
            insert_or_increment(mymap, e, 1);
        }
        
        for(string e : vB){
            insert_or_increment(mymap, e, 1);
        }
        
        for(pair<string, int> p : mymap){
            if(p.second==1){
                ans.push_back(p.first);
            }
        }
        
        return ans;
    }
};