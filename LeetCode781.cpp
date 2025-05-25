// tc - O(n)
// sc - O(n)
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int> mp;
            int answer=0;
            for(int i=0; i<answers.size(); i++) mp[answers[i]]++;
            for(auto x : mp){
                if(x.second>=x.first+1){
                    while(x.second>=x.first+1){
                        answer+=x.first+1;
                        x.second-=x.first+1;
                    }
                }
                if(x.second!=0 && x.second < x.first+1){ 
                    answer+=x.first+1;
                }
            }
            return answer;
        }
    };

    class Solution {
        public:
            int numRabbits(vector<int>& answers) {
                unordered_map<int,int> mp;
                int result=0;
                for(int i=0; i<answers.size(); i++){
                    if(!mp[answers[i]+1]){
                        result+=answers[i]+1; // we started a new colour group
                        if(answers[i]==0) continue;
                        mp[answers[i]+1]=1;
                    }
                    else{
                        mp[answers[i]+1]++;
                        int key = answers[i]+1;
                        int value = mp[key];
                        if(key==value){ // we found all the rabbits of the group
                            // eliminate the group
                            mp.erase(key);
                        }
                    }
                }
                return result;
            }
        };