class Solution {
public:
    vector<vector<string>> res;
    void solveQueens(int n,int row,vector<vector<string>> &board, unordered_set<int> &colSet,unordered_set<int> &diagSet,unordered_set<int> &antiDiagSet){
        
        if(row==n){
            vector<string> temp;
            for(auto &q:board){
                string w="";
                for(auto c:q) w+=c;

                temp.push_back(w);
            }

            res.push_back(temp);
            return;
        }

        for(int col=0;col<n;col++){
            if(colSet.count(col)==1 || diagSet.count(row-col)==1 || antiDiagSet.count(row+col)==1) continue;

            board[row][col]='Q';
            colSet.insert(col);
            diagSet.insert(row-col);
            antiDiagSet.insert(row+col);

            solveQueens(n,row+1,board,colSet,diagSet,antiDiagSet);
            
            board[row][col]='.';
            colSet.erase(col);
            diagSet.erase(row-col);
            antiDiagSet.erase(row+col);


        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> board(n,vector<string>(n,"."));
        unordered_set<int> colSet;
        unordered_set<int> diagSet;
        unordered_set<int> antiDiagSet;
        solveQueens(n,0,board,colSet,diagSet,antiDiagSet);
        return res;
    }
};