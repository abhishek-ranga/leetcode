class Solution {
public:
    int isPrime(int n){
        if(n<=1) return 0;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0) return 0;
        }
        return 1;
    }
    int smallestValue(int n) {
        if(isPrime(n)) return n;
        int sum=0;
        for(int i=1; i<sqrt(n); i++){
            if(isPrime(i) && n%i==0){
                int m=n;
                while(m%i==0){
                    sum+=i;
                    m/=i;
                }
            }
        }
        for(int i=sqrt(n); i>1; i--){
            if(isPrime(n/i) && n%i==0){
                int m=n;
                while(m%(n/i)==0){
                    sum+=(n/i);
                    m/=(n/i);
                }
            }
        }
        if(sum==n) return n;
        return smallestValue(sum);
    }
};