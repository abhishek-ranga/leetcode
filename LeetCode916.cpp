class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_freq(26,0);
        for(int i=0; i<words2.size(); i++){
            vector<int> temp_freq(26,0); 
            for(int j=0; j<words2[i].size(); j++){
                temp_freq[words2[i][j]-'a']++;
            }
            for(int i=0; i<26; i++){
                max_freq[i] = max(max_freq[i],temp_freq[i]);
            }
        }
        vector<string> answer;
        for(int i=0; i<words1.size(); i++){
            vector<int> curr_freq(26,0);
            for(int j=0; j<words1[i].size(); j++){
                curr_freq[words1[i][j]-'a']++;
            }
            bool flag = true;
            for(int i=0; i<26; i++){
                if(max_freq[i]>curr_freq[i]){
                    flag = false;
                    break;
                }
            }
            if(flag==true) answer.push_back(words1[i]);
        }
        return answer;
    }
};