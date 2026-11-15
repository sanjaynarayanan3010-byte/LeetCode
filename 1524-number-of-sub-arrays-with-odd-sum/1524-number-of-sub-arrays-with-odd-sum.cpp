class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int N = arr.size();
        long ans = 0;
        int even = 0, odd = 0, cs = 0;
        for(int i : arr){
            cs += i;
            if(cs & 1) {
                ans++;
                ans += even;
                odd++;
            }
            else {
                ans += odd;
                even++;
            }
        }
        return ans % mod;
    }
};