class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char ch:s) mp[ch]++;
        bool odd = 0;
        int size = 0;
        for(auto it:mp){
            size += ((it.second / 2) * 2);
            if(it.second & 1) odd = 1;
        }
        return (odd ? size + 1 : size);
    }
};