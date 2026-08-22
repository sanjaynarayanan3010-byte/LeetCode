class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int num = n;
        while(num){
            sum += num%10;
            pro *= num%10;
            num /= 10;
        }
        return (n % (sum + pro) == 0);
    }
};