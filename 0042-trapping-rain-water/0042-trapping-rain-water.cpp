class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, cur = 0;
        stack<int> stk;
        for(int cur = 0; cur < height.size(); cur++){
            // cout << cur << endl;
            // if(!stk.empty()){
            //     cout << "stack: ";
            //     vector<int> tmp(&stk.top()+1-stk.size(), &stk.top()+1);
            //     for(int i = 0; i < tmp.size(); i++){
            //         cout << tmp[i] << " ";
            //     }
            //     cout << endl;
            // }
            while(!stk.empty() && height[cur] > height[stk.top()]){
                int top = stk.top(); stk.pop();
                // cout << "pop: " << top << endl;
                if(stk.empty()){
                    break;
                }
                //top is bounded by previous bar in the stack and current bar   
                int dist = cur - stk.top() - 1;
                //the left and right walls are : stk.top(), cur
                int bounded_height = min(height[stk.top()], height[cur]) - height[top];
                ans += dist * bounded_height;
                // cout << "[" << stk.top() << ", " << cur << "] " << ans << endl;
            }
            //the current bar is bounded by previous bar in the stack
            stk.push(cur);
        }
        return ans;
    }
};