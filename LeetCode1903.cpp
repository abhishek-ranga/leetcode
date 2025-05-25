class Solution {
public:
    string largestOddNumber(string num) {
        // if(num[num.length()-1]%2!=0) return num;
        for(int i=num.length()-1; i>=0; i--){
            if(num[i]%2!=0) return num.substr(0,i+1);
        }
        return "";
    }
};