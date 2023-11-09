class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastMin = INT_MAX;
        int ans = 0;
        
        for(int price : prices){
            if(price - lastMin > 0){
                ans += (price - lastMin);
                //lastMin is used, so update it
                lastMin = price;
            }else{
                //continue to find the minimum
                lastMin = min(lastMin, price);
            }
        }
        
        return ans;
    }
};

//monotonic deque