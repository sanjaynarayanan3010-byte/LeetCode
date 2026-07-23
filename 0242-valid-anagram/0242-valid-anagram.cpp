class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        unordered_set<string> st;
        st.insert(s);
        sort(t.begin(),t.end());
        return st.contains(t);
    }
};