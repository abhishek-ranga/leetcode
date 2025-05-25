class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=0; i<number.length()-1; i++){
            if(number[i]==digit && number[i+1]>digit) return number.substr(0,i)+number.substr(i+1);
        }
        int i;
        for(i=number.length()-1; i>=0; i--){
            if(number[i]==digit) break;
        }
        return number.substr(0,i)+number.substr(i+1);
    }
};