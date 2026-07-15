class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddCount = 0;
        int evenCount = 0;
        int numCount = 0;
        int num = 1;
        while(numCount<n){
            if(num&1) oddCount += num;
            else{
                evenCount += num;
                numCount++;
            }
            num++;
        }
        return gcd(oddCount , evenCount);
    }
};