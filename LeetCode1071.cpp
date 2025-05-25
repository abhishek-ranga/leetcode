class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        return str1.substr(0,gcd(str1.size(),str2.size()));
    }
};

// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         string res="";
//         bool flag = true;
//         int i=0;
//         while(flag){
//             if(str1[i]==str2[i]){
//                 res.push_back(str1[i]);
//                 i++;
//             } 
//             else flag = false;
//         }
//         return res;
//     }
// };