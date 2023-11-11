
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> ans;
        unordered_set<int> seen, seen_mul;
        
        int encoded = 0;
        
        //need to ensure substring of length <= 9 won't be put into the set
        for(int i = 0; i < 9; ++i){
            encoded = ((encoded << 2) & 0xFFFFF) | ((s[i]>>1) & 3);
        }
        
        for(int i = 9; i < n; ++i){
            /*
            note:
            A: 65 = 1000001, last 3 bit: 1, 3rd+2nd last bits: 0
            C: 67 = 1000011, last 3 bit: 3, 3rd+2nd last bits: 1
            G: 71 = 1000111, last 3 bit: 7, 3rd+2nd last bits: 3
            T: 84 = 1010100, last 3 bit: 4, 3rd+2nd last bits: 2
            their 3rd+2nd last bits are all different,
            so we can encode a string of "ACGT" by their last 3rd+2nd last bits
            
            to take 3rd+2nd last bits, 
            we use s[i]>>1 & 3(this take 2 bits for each char),
            not s[i] & 6!!(it will take 3 bits)
            */
            
            /*
            the original version use the last 3 digits to represent each char,
            so it needs totally 30 char for each substr,
            it's fine to use "int" to contain it,
            but there will be (encoded << 3) later and it will cause overflow
            */
            // cout << s[i] << ": " << ((s[i]>>1) & 3) << endl;
            encoded = ((encoded << 2) & 0xFFFFF) | ((s[i]>>1) & 3);
            // encoded = ((encoded << 2) & 0xFFFFF) | (s[i] - 64) % 5;
            // if(i >= 9) cout << s.substr(i-9, 10) << ", " << encoded << endl;
            if(seen_mul.find(encoded) == seen_mul.end() && 
               !seen.insert(encoded).second){
                ans.push_back(s.substr(i-9, 10));
                seen_mul.insert(encoded);
            }
        }
        
        return ans;
    }
};