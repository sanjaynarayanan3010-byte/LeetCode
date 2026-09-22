class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int c = 0;
        for(int i=1;i<=(n+k);i++){
            if(abs(n - i) <= k && (n & i) == 0) c += i;
        }
        return c;
    }
};