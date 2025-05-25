class Solution {
public:
    int addDigits(int num) {
        int numsum = 0;
        while(num){
            numsum+=num%10;
            num/=10;
        }
        if(numsum<10) return numsum;
        else return addDigits(numsum);
    }
};

class Solution {
public:
    int addDigits(int num) {
      int sum=0;
        while(num>9)
        {
            while(num)
            {
                sum+=(num%10);
                num/=10;
            }
            num=sum;
            sum=0;
        }
        return num;
    }
};