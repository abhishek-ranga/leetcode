class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int result = INT_MIN;
        for(int i=0; i<sentences.size(); i++){
            int current = 1;
            for(int j=0; j<sentences[i].size(); j++){
                if(sentences[i][j]==' ') current++;
            }
            if(current>result){
                result = current;
            }
        }
        return result;
    }
};