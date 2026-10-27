class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++) grid[row] += '.';
        }
        for(int row=0;row<m-1;row++){
            for(int col=1;col<n;col++) grid[row][col] = '#';
        }
        return grid;
    }
};