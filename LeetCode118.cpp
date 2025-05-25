class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; i++){
            vector<int> r;
            int current = 1;
            for(int j=0; j<=i; j++){
                r.push_back(current);
                current = current * (i-j)/(j+1);
            }
            res.push_back(r);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; i++){
            vector<int> r(i+1);
            int current = 1;
            for(int j=0; j<=i; j++){
                r[j]=current;
                current = current * (i-j)/(j+1);
            }
            res.push_back(r);
        }
        return res;
    }
};