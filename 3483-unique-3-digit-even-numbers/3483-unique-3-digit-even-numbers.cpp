class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int N = digits.size();
        unordered_set<int> st;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i == j) continue;
                for(int k=0;k<N;k++){
                    if(k == j || k == i) continue;
                    int num = (digits[i] * 100);
                    num += (digits[j] * 10);
                    num += digits[k];
                    if(num % 2 == 0 && digits[i] != 0) st.insert(num);
                }
            }
        }
        return st.size();
    }
};