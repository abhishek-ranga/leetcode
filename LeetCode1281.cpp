class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, product=1;
        while(n>0){
            int lastdigit = n%10;
            sum+=lastdigit;
            product*=lastdigit;
            n/=10;
        }
        return product-sum;
    }
};