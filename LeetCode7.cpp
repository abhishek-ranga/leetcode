class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        while(x){
            num*=10;
            num+=(x%10);
            x/=10;
        }
        if(num>INT_MAX || num<INT_MIN) return 0;
        else return (int)num;
    }
};

class Solution {                      
public:
    int reverse(int x) {
        int r=0;      // decleare r 
        while(x){
         if (r>INT_MAX/10 || r<INT_MIN/10) return 0; // check 32 bit range if r is outside the range then return 0 
         r=r*10+x%10; // find remainder and add its to r
         x=x/10;     // Update the value of x
        } 
        return r;  // if r in the 32 bit range then return r
    }
}; 