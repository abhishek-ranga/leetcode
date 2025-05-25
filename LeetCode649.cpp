class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> q,r,d;
        for(int i=0; i<s.length(); i++){
            q.push(i);
            if(s[i]=='R') r.push(i);
            if(s[i]=='D') d.push(i);
        }
        while(q.size()>1){
            if(s[q.front()]=='X') q.pop();
            else if(s[q.front()]=='R'){
                // check for victory
                if(d.size()==0) return "Radiant";
                else{
                    // take the rights of next D
                    s[d.front()]='X'; d.pop();
                    // inka kaam ho chuka hai
                    q.push(q.front()); q.pop();
                    r.push(r.front()); r.pop();
                }
            }
            else{ // s[q.front()=='D]
                // check for victory
                if(r.size()==0) return "Dire";
                else{
                    // take the rights of next R
                    s[r.front()]='X'; r.pop();
                    // inka kaam ho chuka hai
                    q.push(q.front()); q.pop();
                    d.push(d.front()); d.pop();
                }
            }
        }
        if(s[q.front()]=='R') return "Radiant";
        else return "Dire";
    }
};