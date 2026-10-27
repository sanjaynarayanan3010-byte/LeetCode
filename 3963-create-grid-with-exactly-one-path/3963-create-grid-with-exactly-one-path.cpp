class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for(int row=0;row<m;row++) grid[row][0] = '.';
        for(int col=1;col<n;col++) grid[m-1][col] = '.';
        return grid;
    }
};