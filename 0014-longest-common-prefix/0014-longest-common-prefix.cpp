class TrieNode{
    public:
    TrieNode* chars[26];
    bool end;

    TrieNode(){
        end = 0;
        for(int i=0;i<26;i++) chars[i] = NULL;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();

        for(string& s : strs){
            TrieNode* node = root;
            for(char ch : s){
                int idx = ch - 'a';
                if(node->chars[idx] == NULL) node->chars[idx] = new TrieNode();
                node = node->chars[idx];
            }
            node->end = 1;
        }

        string ans = "";
        TrieNode* node = root;
        while(1){
            if(node->end) break;
            int childcount = 0, index = -1;
            for(int i=0;i<26;i++) {
                if(node->chars[i] != NULL) {
                    childcount++;
                    index = i;
                }
            }
            if(childcount != 1) break;
            ans += ('a' + index);
            node = node->chars[index];
        }
        return ans;
    }
};