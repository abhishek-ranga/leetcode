class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(int i=0;i<str.length();i++){
            if(str[i]=='6'){
                str[i]='9';
                break;
            }
        }
        return stoi(str);
    }
};

class Solution {
public:
    int maximum69Number (int num) 
    {
        //first encountered '6' from left = last encountered '6' from right
        
        int rightDigCount = -1; //number of digits to right of last encountered '6'
        int digCount = 0; //number of digits to right of any dig at some instance
        int temp = num; 
        //====================================================================
        while(temp > 0) //digits are being recorded from right to left of num
        {
            int dig = temp % 10;
            if (dig == 6) rightDigCount = digCount; //record the rightDigCount when a '6' is encountered
            
            digCount++;
            temp = temp / 10;
        }
        //======================================================================
        if (rightDigCount == -1) return num;
        int ans = num + (3 * pow(10, rightDigCount));
        return ans;
    }
};

class Solution:
    def maximum69Number (self, num: int) -> int:
        i = 0 
        tem = num
        sixidx = -1 
        while tem > 0:
            if tem % 10 == 6:
                sixidx = i  #refresh sixidx when found 6 at large digit.
            tem = tem//10
            i += 1
        return (num + 3 *(10**sixidx)) if sixidx != -1 else num