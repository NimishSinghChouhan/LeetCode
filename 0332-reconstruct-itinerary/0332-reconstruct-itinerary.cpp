class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> edges;
        
        for(vector<string>& ticket : tickets){
            edges[ticket[0]].insert(ticket[1]);
        }
        
        vector<string> route;
        stack<string> stk;
        stk.push("JFK");
        
        while(!stk.empty()){
            while(edges.find(stk.top()) != edges.end() && !edges[stk.top()].empty()){
                string next = *edges[stk.top()].begin();
                edges[stk.top()].erase(edges[stk.top()].begin());
                stk.push(next);
            }
            route.insert(route.begin(), stk.top());
            stk.pop();
        }
        
        return route;
    }
};