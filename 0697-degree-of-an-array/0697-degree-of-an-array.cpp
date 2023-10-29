class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> count;
        
        for(int num : nums){
            if(count.find(num) == count.end()){
                count[num] = 1;
            }else{
                count[num] += 1;
            }
        }
        
        int maxfreq, maxele;
        vector<int> candidates;
        
        map<int, int>::iterator it = max_element(count.begin(), count.end(), [] (const pair<int, int> & p1, const pair<int, int> & p2) {return p1.second < p2.second;});
        maxfreq = it->second;
        
        for(map<int, int>::iterator it = count.begin(); it!=count.end(); it++){
            if(it->second == maxfreq){
                candidates.push_back(it->first);
            }
        }
        
        int ans = INT_MAX;
        for(int candidate : candidates){
            vector<int> tofind = {candidate};
            int substart = find(nums.begin(), nums.end(), candidate) - nums.begin();
            int subend = find_end(nums.begin(), nums.end(), tofind.begin(), tofind.end()) - nums.begin();
            cout << maxele << " " << substart << " " << subend << endl;
            ans = min(ans, subend - substart + 1);
        }
        return ans;
    }
};