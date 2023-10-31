class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() >= 2){
            //y is always >= x
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            
            if(x != y) pq.push(y-x);
        }
        
        //note its pq.top() not pq[0]!
        return pq.size() > 0 ? pq.top() : 0;
    }
};