class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfits=0;
        int mini=prices[0];
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-mini;
            maxProfits=max(maxProfits,cost);
            mini=min(mini,prices[i]);
        }
        return maxProfits;
        
    }
};