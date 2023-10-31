 
class Solution {
public:
    template <typename T>
    vector<size_t> sort_indexes(const vector<T> &v) {
      // initialize original index locations
      vector<size_t> idx(v.size());
      iota(idx.begin(), idx.end(), 0);

      // sort indexes based on comparing values in v
      sort(idx.begin(), idx.end(),
           [&v](size_t i1, size_t i2) {return v[i1].compare(v[i2]) < 0;});

      return idx;
    }
    
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<size_t> ixs1 = sort_indexes(list1);
        vector<size_t> ixs2 = sort_indexes(list2);
        vector<string> ans;
        
        int cur1 = 0, cur2 = 0;
        int lastIxSum = INT_MAX;
        while(cur1 < list1.size() && cur2 < list2.size()){
            size_t ix1 = ixs1[cur1];
            size_t ix2 = ixs2[cur2];
            string s1 = list1[ix1];
            string s2 = list2[ix2];
            
            int comparision = s1.compare(s2);
            if(comparision == 0){
                cur1++;
                cur2++;
                // cout << s1 << endl;
                // cout << ix1+ix2 << " " << lastIxSum << endl;
                if(ix1 + ix2 < lastIxSum){
                    ans.clear();
                    ans.push_back(s1);
                    lastIxSum = ix1 + ix2;
                }else if(ix1 + ix2 == lastIxSum){
                    ans.push_back(s1);
                }
            }else if(comparision < 0){
                cur1++;
            }else{
                cur2++;
            }
        }
        
        return ans;
    }
};