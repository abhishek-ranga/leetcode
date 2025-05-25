class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')) return false;
        // while(s[i]==' ') i++;
        // if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')) return false;
        bool nigga = false;
        if(s[i]=='+'||s[i]=='-'){
            nigga = true;
            i++;
        }
        bool sign = false;
        bool num = false;
        bool dot = false;
        bool expo = false;
        while(i<s.length()){
            if(s[i]=='+'||s[i]=='-'){
                if(i==s.length()-1) return false;
                if(nigga){
                    if(num==false) return false;
                }
                if(num){
                    if(expo==false) return false; // matlab kuch aisa 6+1
                    else if(expo){
                        if(s[i-1]=='e'|s[i-1]=='E'){ // 7e+7
                            sign = true;
                            i++;
                        }
                        else return false; // 7e7+1
                    }
                }
                if(s[i-1]=='.') return false;

                // else if(sign==true){
                //     if(expo) i++;
                //     else return false;
                // }
                // else{
                //     sign=true;
                //     i++;
                // }
            }
            if(s[i]>='0'&&s[i]<='9'){
                num = true;
                i++;
            }
            if(s[i]=='.'){
                if(i==s.length()-1 && i!=0){
                    if(s[i-1]>='0'&&s[i-1]<='9') i++;
                    else return false;
                }
                if(dot==false && expo==false){
                    dot=true;
                    i++;
                }
                else if(dot==false && expo==true) return false;
                else if(dot==true) return false;
            }
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
                if(s[i]=='e'||s[i]=='E'){
                    if(expo==true) return false;
                    else{
                        if(s[i-1]=='.'){
                            if(num==false) return false;
                            else expo = true;
                            i++;
                        }
                        else{
                            if(s[i-1]>='0'&&s[i-1]<='9'){
                                expo = true;
                                i++;
                            }
                            else return false;
                        }
                    } 
                }
                else return false;
            }
        }
        if(nigga==true&&s.length()==1) return false;
        if(dot==true&&i==1) return false;
        if(expo==true && (s[i-1]=='e' || s[i-1]=='E')) return false;
        return true;
    }
};