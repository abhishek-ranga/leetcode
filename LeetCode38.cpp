class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str = countAndSay(n-1);
        // str = "3322251" -> "23 32 15 11"
        string ztr = "";
        int freq = 1; // 2
        char ch = str[0]; // 3
        for(int i=1; i<str.length(); i++){
            char dh = str[i]; // 2nd iteration dh = 2
            if(ch==dh){
                freq++;

            }
            else{ // ch!=dh
                ztr += (to_string(freq)+ch);
                freq = 1;
                ch = dh; // ch = str[i]
            }
        }
        ztr += (to_string(freq)+ch);
        return ztr;
    }
};