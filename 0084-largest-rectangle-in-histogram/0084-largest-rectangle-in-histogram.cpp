class Solution
{
public:
    int largestRectangleArea(vector<int>& arr) {
        int N = arr.size();
        vector<int> prev(N, -1);
        stack<int> st;
        for(int i=0;i<N;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()) prev[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<int> next(N, -1);
        for(int i=0;i<N;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            int p = prev[i];
            int n = next[i];
            if(n == -1) n = N;
            ans = max(ans, arr[i] * (n - p - 1));
        }
        return ans;
    }
};