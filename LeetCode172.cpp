class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        // return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
        int result = 0;
        for(int i=5; n/i>0; i*=5){
            result += (n/i);
        }
        return result;
    }
};