class TrieNode{
    public:
        TrieNode* chars[26];
        string word;

        TrieNode(){
            word = "";
            for(int i=0;i<26;i++) chars[i] = NULL;
        }
};

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col, TrieNode* node, vector<string>& ans){
        int R = grid.size(), C = grid[0].size();
        if(row < 0 || row >= R || col < 0 || col >= C || grid[row][col] == '#') return;

        char ch = grid[row][col];
        int idx = ch - 'a';
        if(node->chars[idx] == NULL) return;

        node = node->chars[idx];

        if(!node->word.empty()){
            ans.push_back(node->word);
            node->word = "";
        }

        grid[row][col] = '#';

        dfs(grid, row+1, col, node, ans);
        dfs(grid, row-1, col, node, ans);
        dfs(grid, row, col+1, node, ans);
        dfs(grid, row, col-1, node, ans);

        grid[row][col] = ch;
    }

    vector<string> findWords(vector<vector<char>>& grid, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(string& s : words){
            TrieNode* node = root;
            for(char ch : s){
                int idx = ch - 'a';
                if(node->chars[idx] == NULL) {
                    node->chars[idx] = new TrieNode();
                }
                node = node->chars[idx];
            }
            node->word = s;
        }

        vector<string> ans;
        int R = grid.size(), C = grid[0].size();
        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                dfs(grid, row, col, root, ans);
            }
        }
        return ans;
    }
};