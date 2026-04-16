class Solution {
public:
    void backtrack(vector<vector<string>> &board,int row,unordered_set<int> &colSet,unordered_set<int> &diagonalSet,unordered_set<int> &antiDiagonalSet,int n,vector<vector<string>> &res){

        if(row==n){
            vector<string> temp;
            
            for(auto bu:board){
                string res="";
                for(string c:bu) res+=c;
                temp.push_back(res);
            }
            res.push_back(temp);
        }


        for(int col=0;col<n;col++){

            if(colSet.count(col)==1 || diagonalSet.count(row-col)==1 || antiDiagonalSet.count(row+col)==1) continue;

            board[row][col]="Q";
            colSet.insert(col);
            diagonalSet.insert(row-col);
            antiDiagonalSet.insert(row+col);

            backtrack(board,row+1,colSet,diagonalSet,antiDiagonalSet,n,res);
            board[row][col]=".";
            colSet.erase(col);
            diagonalSet.erase(row-col);
            antiDiagonalSet.erase(row+col);
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<string>> board(n,vector<string>(n,"."));
        unordered_set<int> colSet;
         unordered_set<int> diagonalSet;
          unordered_set<int> antiDiagonalSet;
        backtrack(board,0,colSet,diagonalSet,antiDiagonalSet,n,res);
        
        return res;
        

    }
};