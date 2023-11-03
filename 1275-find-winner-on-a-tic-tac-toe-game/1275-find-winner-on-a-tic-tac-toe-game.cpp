class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> a_row(3), a_col(3), b_row(3), b_col(3);
        int aD1 = 0, aD2 = 0, bD1 = 0, bD2 = 0;
        for(int i = 0; i < moves.size(); i++){
            vector<int> move = moves[i];
            int r = move[0], c = move[1];
            if(i % 2 == 0){
                //A
                if(++a_row[r] == 3 || ++a_col[c] == 3 ||
                  r == c && ++aD1 == 3 || r + c == 2 && ++aD2 == 3) return "A";
            }else{
                //B
                if(++b_row[r] == 3 || ++b_col[c] == 3 || 
                  r == c && ++bD1 == 3 || r + c == 2 && ++bD2 == 3) return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};