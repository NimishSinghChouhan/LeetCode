class Solution {
public:
    bool checkRecord(string s) {
        //A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
        return count(s.begin(), s.end(), 'A') <= 1 &&
            s.find("LLL") == string::npos;
    }
};