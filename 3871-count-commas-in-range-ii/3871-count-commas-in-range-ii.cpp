class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long count=0;
        if(n>=1000 && n<1000000) count+=((n-1000)+1);
        else if(n>=1000000 && n<1000000000) {
            count+=((n-1000000)+1);
            count+=((n-1000)+1);
        }
        else if(n>=1000000000 && n<1000000000000) {
            count+=((n-1000000000)+1);
            count+=((n-1000000)+1);
            count+=((n-1000)+1);
        }
        else if(n>=1000000000000 && n<=1000000000000000){
            if(n==1000000000000000) count+=1;
            count+=((n-1000000000000)+1);
            count+=((n-1000000000)+1);
            count+=((n-1000000)+1);
            count+=((n-1000)+1);
        }
        return count;
    }
};