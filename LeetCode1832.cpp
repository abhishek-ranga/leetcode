class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> check(26);
        for(int i=0; i<sentence.length(); i++){
            check[sentence[i]-97] = 1;
        }
        for(int i=0; i<check.size(); i++){
            if(check[i]==0) return false;
        }
        return true;
    }
};

