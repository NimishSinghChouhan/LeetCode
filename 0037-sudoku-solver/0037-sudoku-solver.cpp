struct cell{
    uint8_t val;
    uint8_t numPossibilities;
    //if bitset[i] is 1, then current cell cannot be i
    bitset<10> constraints;
    
    cell(): val(0), numPossibilities(9), constraints() {};
};

class Solution {
public:
    array<array<cell, 9>, 9> cells;
    
    vector<pair<int, int>> emptys;
    
    bool updateConstraints(int i, int j, int excludedVal){
        cell& c = cells[i][j];
        
        //already excluded
        if(c.constraints[excludedVal]) return true;
        //found a conflict
        if(c.val == excludedVal) return false;
        
        c.constraints.set(excludedVal);
        --c.numPossibilities;
        if(c.numPossibilities > 1) return true;
        
        //now c.numPossibilities == 1
        //so cells[i][j] is determined
        for(int v = 1; v <= 9; ++v){
            if(!c.constraints[v]){
                return setCell(i, j, v);
            }
        }
        
        //can never reach here
        // assert(false);
        return false;
    };
    
    bool setCell(int i, int j, int v){
        cell& c = cells[i][j];
        
        //this cell has already been set
        if(c.val == v) return true;
        
        //found a conflict
        if(c.constraints[v]) return false;
        
        //1111111110
        c.constraints = bitset<10>(0x3FE);
        //because the value of current cell is determined
        c.constraints.reset(v);
        c.numPossibilities = 1;
        c.val = v;
        
        for(int k = 0; k < 9; ++k){
            int gi = i/3*3+k/3, gj = j/3*3+k%3;
            if(i != k && !updateConstraints(k, j, v)){
                return false;
            } 
            if(j != k && !updateConstraints(i, k, v)){
                return false;
            }
            if(i != gi && j != gj && !updateConstraints(gi, gj, v)){
                return false;
            }
        }
        
        return true;
    };
    
    bool findValuesForEmptyCells(){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(cells[i][j].val == 0){
                    emptys.push_back({i, j});
                }
            }
        }
        
        sort(emptys.begin(), emptys.end(), 
             [this](const pair<int, int>& a, const pair<int, int>& b){
                 return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities;
             });
        
        //false for fail
        return backtrack(0);
    };
    
    bool backtrack(int k){
        //all cells set
        if(k >= emptys.size()) return true;
        auto p = emptys[k];
        int i = p.first, j = p.second;

        cell& c = cells[i][j];
        //current cell already set, continue the next
        if(c.val) return backtrack(k+1);

        array<array<cell, 9>, 9> snapshot(cells);

        //try 1-9 for current cell
        for(int v = 1; v <= 9; ++v){
            //cannot fill v into current cell
            if(c.constraints[v]) continue;

            if(setCell(i, j, v)){
                bool res = backtrack(k+1);
                if(res) return res;
            }

            cells = snapshot;
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                if(!setCell(i, j, board[i][j]-'0')){
                    //there is a conflict
                    return;
                }
            }
        }
        
        if(!findValuesForEmptyCells()){
            //there is a conflict, the sudoku is unsolvable
            return;
        }
        
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(cells[i][j].val){
                    board[i][j] = cells[i][j].val + '0';
                }
            }
        }
    }
};