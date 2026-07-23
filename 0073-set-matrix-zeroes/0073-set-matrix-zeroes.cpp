class Solution {
public:
    int mod = 1e9 + 7;

    void right(int row,int col,vector<vector<int>>& matrix,int R,int C){
        for(int cc=col+1;cc<C;cc++){
            if(matrix[row][cc] != 0) matrix[row][cc] = mod;
            else return;
        }
    }

    void left(int row,int col,vector<vector<int>>& matrix,int R,int C){
        for(int cc=col-1;cc>=0;cc--){
            if(matrix[row][cc] != 0) matrix[row][cc] = mod;
            else return;
        }
    }

    void top(int row,int col,vector<vector<int>>& matrix,int R,int C){
        for(int cr=row-1;cr>=0;cr--){
            if(matrix[cr][col] != 0) matrix[cr][col] = mod;
            else return;
        }
    }

    void down(int row,int col,vector<vector<int>>& matrix,int R,int C){
        for(int cr=row+1;cr<R;cr++){
            if(matrix[cr][col] != 0) matrix[cr][col] = mod;
            else return;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(matrix[row][col] == 0){
                    right(row,col,matrix,R,C);
                    left(row,col,matrix,R,C);
                    top(row,col,matrix,R,C);
                    down(row,col,matrix,R,C);
                }
            }
        }
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                if(matrix[row][col] == mod) matrix[row][col] = 0;
            }
        }
    }
};