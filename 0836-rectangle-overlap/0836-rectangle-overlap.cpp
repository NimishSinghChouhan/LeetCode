class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //min(x22-x11, x12-x21)
        //min(y22-y11, y12-y21)
        return min(rec2[2]-rec1[0], rec1[2]-rec2[0]) > 0 && \
            min(rec2[3]-rec1[1], rec1[3]-rec2[1]) > 0;
    }
};